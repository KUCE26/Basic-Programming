"""문제 세트의 언어별 모범 답안 실행 (build.py · verify.py 공용)

세트 언어는 problems/setN/meta.json 의 "lang" (python · c · cpp). meta.json 이 없으면 python.
- python : pK_sol.py 를 python3 -I 로 실행
- c      : pK_sol.c   를 gcc -std=c11 -O0 -lm 으로 컴파일해 실행 (사이트의 Compiler Explorer 와 같은 옵션)
- cpp    : pK_sol.cpp 를 g++ -std=c++17 -O2 로 컴파일해 실행
"""
import json
import os
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXT = {"python": "py", "c": "c", "cpp": "cpp"}
_bin_cache = {}


def set_lang(n):
    mp = os.path.join(ROOT, "problems", f"set{n}", "meta.json")
    if os.path.exists(mp):
        return json.load(open(mp, encoding="utf-8")).get("lang", "python")
    return "python"


def sol_path(n, k, lang):
    return os.path.join(ROOT, "problems", f"set{n}", f"p{k}_sol.{EXT[lang]}")


def norm(s):
    return "\n".join(l.rstrip() for l in s.rstrip("\n").split("\n"))


def _compile(path, lang):
    if path in _bin_cache:
        return _bin_cache[path]
    exe = os.path.join(tempfile.gettempdir(), "bp_" + os.path.basename(os.path.dirname(path)) + "_" + os.path.basename(path).split("_")[0])
    if lang == "c":
        cmd = ["gcc", "-std=c11", "-Wall", "-O0", "-o", exe, path, "-lm"]
    else:
        cmd = ["g++", "-std=c++17", "-Wall", "-O2", "-o", exe, path]
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode:
        raise RuntimeError(f"{path}: 컴파일 실패\n{r.stderr.strip()}")
    if r.stderr.strip():
        raise RuntimeError(f"{path}: 컴파일 경고 (경고 없이 컴파일돼야 함)\n{r.stderr.strip()}")
    _bin_cache[path] = exe
    return exe


def run(path, inp, lang="python"):
    """모범 답안을 입력 inp 로 실행 → (정규화한 stdout, 오류 메시지 또는 '')"""
    if lang == "python":
        cmd = [sys.executable, "-I", path]
    else:
        cmd = [_compile(path, lang)]
    r = subprocess.run(cmd, input=inp, capture_output=True, text=True, timeout=5)
    err = ""
    if r.returncode:
        err = (r.stderr.strip().splitlines() or [f"exit code {r.returncode}"])[-1]
    return norm(r.stdout), err
