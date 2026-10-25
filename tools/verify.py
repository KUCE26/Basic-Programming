"""세트 하나 검사: 모범 답안을 모든 테스트로 실행하고, md 의 입출력 예시와 대조하고, 금지 문법·테스트 수를 확인한다.

사용법:  python3 tools/verify.py N
세트 언어(python · c · cpp)는 problems/setN/meta.json 의 "lang" 을 따른다 (tools/langs.py).
"""
import json, os, re, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from langs import ROOT, norm, run, set_lang, sol_path  # noqa: E402

BASE = os.path.join(ROOT, "problems")
BANNED_PY = re.compile(r"^\s*(import |from \S+ import|try:|except\b|class |with open|open\()", re.M)


def examples(md):
    ins = re.findall(r"## 입력 예시 \d+\s*\n```\n?(.*?)```", md, re.S)
    outs = re.findall(r"## 출력 예시 \d+\s*\n```\n?(.*?)```", md, re.S)
    return [i if i.endswith("\n") else i + "\n" for i in ins], [norm(o) for o in outs]


def check_set(n):
    d = os.path.join(BASE, f"set{n}")
    lang = set_lang(n)
    count = len([f for f in os.listdir(d) if re.fullmatch(r"p\d+\.md", f)])
    problems = {}
    issues = []
    for k in range(1, count + 1):
        mdp = f"{d}/p{k}.md"
        sol = sol_path(n, k, lang)
        if not os.path.exists(sol):
            issues.append(f"set{n} p{k}: 모범 답안 없음 ({os.path.basename(sol)})")
            continue
        md = open(mdp, encoding="utf-8").read()
        src = open(sol, encoding="utf-8").read()
        if lang == "python" and BANNED_PY.search(src):
            issues.append(f"set{n} p{k}: banned construct in solution: {BANNED_PY.search(src).group(0).strip()}")
        if "## 시작 코드" not in md and lang != "python":
            issues.append(f"set{n} p{k}: '## 시작 코드' 절이 없음 (C/C++ 문제는 필수)")
        tp = f"{d}/p{k}_tests.txt"
        raw = open(tp, encoding="utf-8").read() if os.path.exists(tp) else ""
        tests = [t if t.endswith("\n") else t + "\n" for t in raw.split("=====\n")]
        tests = [t for t in tests if t.strip()]
        ins, outs = examples(md)
        if len(ins) != len(outs) or not ins:
            issues.append(f"set{n} p{k}: example count mismatch {len(ins)} in / {len(outs)} out")
        no_input = all(not i.strip() for i in ins)
        try:
            for i, (inp, exp) in enumerate(zip(ins, outs), 1):
                out, err = run(sol, inp, lang)
                if err or out != exp:
                    issues.append(f"set{n} p{k}: example {i} mismatch\n  expected: {exp!r}\n  got:      {out!r} {err}")
            cases = []
            for t in (tests or ["\n"]):
                out, err = run(sol, t, lang)
                if err:
                    issues.append(f"set{n} p{k}: test error on {t!r}: {err}")
                cases.append([t, out])
        except RuntimeError as e:
            issues.append(f"set{n} p{k}: {e}")
            cases = []
        if not no_input and len(cases) < 4:
            issues.append(f"set{n} p{k}: only {len(cases)} tests (4개 이상 필요)")
        if not no_input:
            for i, inp in enumerate(ins[:2]):
                if i < len(tests) and tests[i] != inp:
                    issues.append(f"set{n} p{k}: 테스트 {i+1} 이 입력 예시 {i+1} 과 다름")
        title = md.split("\n", 1)[0].lstrip("# ").strip()
        problems[k] = {"title": title, "cases": cases}
    return problems, issues


if __name__ == "__main__":
    n = sys.argv[1]
    problems, issues = check_set(n)
    json.dump(problems, open(os.path.join(BASE, f"set{n}", "cases.json"), "w", encoding="utf-8"), ensure_ascii=False, indent=1)
    print(f"set{n} ({set_lang(n)}): {len(issues)} issues")
    for i in issues:
        print(" -", i)
    for k, p in problems.items():
        print(f"  p{k} {p['title']} ({len(p['cases'])} tests)")
