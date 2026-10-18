"""문제 원본(problems/setN/pK.md · pK_sol.py · pK_tests.txt) → assets/problems.js

사용법:  python3 tools/build.py
- 모범 답안을 모든 테스트 입력으로 실행해 기대 출력을 만든다 (tools/verify.py 와 같은 규칙).
- 문제 설명(md)의 출력 예시가 실제 실행 결과와 같은지 확인한다.
- 문제 설명을 HTML로 바꿔 assets/problems.js 에 window.BP_PROBLEMS 로 넣는다.
"""
import html
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

SET_INFO = {
    1: ("A", "편의점에서 할인 쿠폰까지", "입출력·리스트·딕셔너리·문자열·조건·반복·함수 10슬롯을 가장 기본형으로 묶은 세트"),
    2: ("B", "지각 시간부터 가변 인자까지", "A세트와 같은 10슬롯, 소재와 요구 출력 형식을 바꾼 변형"),
    3: ("C", "직사각형 밭부터 프로필 카드까지", "윤년·학점 등 조건 분기가 조금 더 긴 세트"),
    4: ("D", "택시 요금부터 최솟값 직접 구하기까지", "FizzBuzz 변형, 두 번째로 큰 값 등 반복문 응용이 많은 세트"),
    5: ("E", "피자 나누기부터 리스트 변환기까지", "구구단 표·더치페이 등 출력 형식 맞추기와 함수 심화가 중심인 세트"),
    6: ("과제", "엘리스 4차시·8차시 과제 15문제", "교수님이 '시험 난이도의 기준'이라고 한 엘리스 과제 원본. 자동 채점이 되도록 입력·출력 코드만 붙였어요"),
}
SET6 = [("산술 연산", "4차시"), ("변수·계산", "4차시"), ("리스트 remove", "4차시"), ("리스트 sort", "4차시"), ("in·논리 연산", "4차시"),
        ("딕셔너리", "4차시"), ("문자열 strip", "4차시"), ("% 포맷팅", "4차시"),
        ("조건문·산술", "8차시"), ("for·print(end=)", "8차시"), ("for·in", "8차시"), ("for·리스트 인덱스", "8차시"),
        ("함수·count/split", "8차시"), ("for·max/min", "8차시"), ("함수·딕셔너리", "8차시")]

SLOTS = ["입출력·산술", "포맷팅·형 변환", "리스트", "딕셔너리", "문자열", "조건문", "for 반복", "while·break", "함수", "함수 심화"]
LESSON = ["2차시", "2·4차시", "3차시", "4차시", "4차시", "5차시", "6차시", "6차시", "7차시", "8차시"]


def norm(s):
    return "\n".join(l.rstrip() for l in s.rstrip("\n").split("\n"))


def run(path, inp):
    r = subprocess.run([sys.executable, "-I", path], input=inp, capture_output=True, text=True, timeout=5)
    if r.returncode:
        raise RuntimeError(f"{path}: {r.stderr.strip().splitlines()[-1]}")
    return norm(r.stdout)


def inline(text):
    text = html.escape(text, quote=False)
    text = re.sub(r"`([^`]+)`", r"<code>\1</code>", text)
    text = re.sub(r"\*\*([^*]+)\*\*", r"<b>\1</b>", text)
    return text


def md_to_html(body):
    """문제 md 본문(제목 아래) → HTML. 제목(##), 번호 목록, 코드 블록, 문단만 쓴다."""
    out = []
    lines = body.split("\n")
    i = 0
    while i < len(lines):
        line = lines[i]
        if line.startswith("```"):
            lang = line[3:].strip()
            j = i + 1
            buf = []
            while j < len(lines) and not lines[j].startswith("```"):
                buf.append(lines[j])
                j += 1
            cls = ' class="lang-python"' if lang == "python" else ""
            out.append(f"<pre{cls}><code>{html.escape(chr(10).join(buf))}</code></pre>")
            i = j + 1
            continue
        if line.startswith("## "):
            out.append(f"<h3>{inline(line[3:].strip())}</h3>")
            i += 1
            continue
        if re.match(r"^\d+\. ", line):
            items = []
            while i < len(lines) and re.match(r"^\d+\. ", lines[i]):
                items.append(f"<li>{inline(re.sub(r'^\d+\. ', '', lines[i]))}</li>")
                i += 1
            out.append("<ol>" + "".join(items) + "</ol>")
            continue
        if line.startswith("- "):
            items = []
            while i < len(lines) and lines[i].startswith("- "):
                items.append(f"<li>{inline(lines[i][2:])}</li>")
                i += 1
            out.append("<ul>" + "".join(items) + "</ul>")
            continue
        if line.strip() == "":
            i += 1
            continue
        para = []
        while i < len(lines) and lines[i].strip() and not lines[i].startswith(("## ", "```", "- ")) and not re.match(r"^\d+\. ", lines[i]):
            para.append(lines[i].strip())
            i += 1
        out.append(f"<p>{inline(' '.join(para))}</p>")
    return "\n".join(out)


def split_sections(md):
    """md → {title, story, sections:[(heading, text)]}"""
    title, rest = md.split("\n", 1)
    title = title.lstrip("# ").strip()
    parts = re.split(r"^## ", rest.strip(), flags=re.M)
    story = parts[0].strip()
    secs = []
    for p in parts[1:]:
        h, _, body = p.partition("\n")
        secs.append((h.strip(), body.strip()))
    return title, story, secs


def build_problem(n, k):
    d = os.path.join(ROOT, "problems", f"set{n}")
    md = open(f"{d}/p{k}.md", encoding="utf-8").read().strip()
    sol_path = f"{d}/p{k}_sol.py"
    sol = open(sol_path, encoding="utf-8").read().strip()
    tests = [t if t.endswith("\n") else t + "\n" for t in open(f"{d}/p{k}_tests.txt", encoding="utf-8").read().split("=====\n")]
    tests = [t for t in tests if t.strip()] or ["\n"]   # 입력이 없는 문제는 빈 입력 하나로 채점

    title, story, secs = split_sections(md)
    starter = ""
    tips = ""
    examples = []
    instr_html = ""
    cur_in = None
    for h, body in secs:
        if h == "시작 코드":
            m = re.search(r"```python\n(.*?)```", body, re.S)
            starter = m.group(1).rstrip("\n") + "\n" if m else ""
        elif h == "지시사항":
            instr_html = md_to_html(body)
        elif h.startswith("입력 예시"):
            cur_in = re.search(r"```\n?(.*?)```", body, re.S).group(1)
        elif h.startswith("출력 예시"):
            out = re.search(r"```\n?(.*?)```", body, re.S).group(1)
            examples.append({"in": cur_in, "out": norm(out)})
        elif h == "Tips":
            tips = md_to_html(body)

    # 예시 출력이 모범 답안 실행 결과와 같은지 확인
    for i, ex in enumerate(examples, 1):
        inp = ex["in"] if ex["in"].endswith("\n") else ex["in"] + "\n"
        got = run(sol_path, inp)
        if got != ex["out"]:
            raise SystemExit(f"set{n} p{k} 예시 {i} 불일치\n기대: {ex['out']!r}\n실행: {got!r}")

    cases = [[t, run(sol_path, t)] for t in tests]
    if not starter:
        starter = f"# {title}\n"
    return {
        "id": f"s{n}q{k}",
        "no": k,
        "title": title,
        "slot": SET6[k - 1][0] if n == 6 else SLOTS[k - 1],
        "lesson": SET6[k - 1][1] if n == 6 else LESSON[k - 1],
        "story": md_to_html(story),
        "instructions": instr_html,
        "examples": examples,
        "tips": tips,
        "starter": starter,
        "solution": sol,
        "cases": cases,
    }


def main():
    sets = []
    total_cases = 0
    for n in range(1, 7):
        label, sub, lead = SET_INFO[n]
        count = 15 if n == 6 else 10
        probs = [build_problem(n, k) for k in range(1, count + 1)]
        total_cases += sum(len(p["cases"]) for p in probs)
        sets.append({"n": n, "label": label, "title": ("엘리스 과제" if n == 6 else f"{label}세트"), "sub": sub, "lead": lead, "problems": probs})
        print(f"set{n}: {count}문제, 테스트 {sum(len(p['cases']) for p in probs)}개")
    data = {"sets": sets, "slots": SLOTS}
    js = "/* tools/build.py 가 problems/ 에서 만든 파일 — 직접 고치지 말고 problems/ 를 고친 뒤 다시 빌드하세요 */\nwindow.BP_PROBLEMS = " + json.dumps(data, ensure_ascii=False) + ";\n"
    out = os.path.join(ROOT, "assets", "problems.js")
    open(out, "w", encoding="utf-8").write(js)
    print(f"→ {out} ({len(js)//1024} KB, 테스트 {total_cases}개)")


if __name__ == "__main__":
    main()
