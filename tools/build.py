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
    1: ("A", "A세트", "편의점에서 할인 쿠폰까지", "입출력·리스트·딕셔너리·문자열·조건·반복·함수 10슬롯을 가장 기본형으로 묶은 세트"),
    2: ("B", "B세트", "지각 시간부터 가변 인자까지", "A세트와 같은 10슬롯, 소재와 요구 출력 형식을 바꾼 변형"),
    3: ("C", "C세트", "직사각형 밭부터 프로필 카드까지", "윤년·학점 등 조건 분기가 조금 더 긴 세트"),
    4: ("D", "D세트", "택시 요금부터 최솟값 직접 구하기까지", "FizzBuzz 변형, 두 번째로 큰 값 등 반복문 응용이 많은 세트"),
    5: ("E", "E세트", "피자 나누기부터 리스트 변환기까지", "구구단 표·더치페이 등 출력 형식 맞추기와 함수 심화가 중심인 세트"),
}
# 6번 이후 세트(엘리스 과제·연습)는 problems/setN/meta.json 에 label·title·sub·lead·slots 가 있다.

SLOTS = ["입출력·산술", "포맷팅·형 변환", "리스트", "딕셔너리", "문자열", "조건문", "for 반복", "while·break", "함수", "함수 심화"]
LESSON = ["2차시", "2·4차시", "3차시", "4차시", "4차시", "5차시", "6차시", "6차시", "7차시", "8차시"]


def set_meta(n):
    d = os.path.join(ROOT, "problems", f"set{n}")
    mp = os.path.join(d, "meta.json")
    if os.path.exists(mp):
        m = json.load(open(mp, encoding="utf-8"))
    else:
        label, title, sub, lead = SET_INFO[n]
        m = {"label": label, "title": title, "sub": sub, "lead": lead, "slots": [list(x) for x in zip(SLOTS, LESSON)]}
    m["count"] = len([f for f in os.listdir(d) if re.fullmatch(r"p\d+\.md", f)])
    return m


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


def build_problem(n, k, meta):
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
        "slot": meta["slots"][k - 1][0],
        "lesson": meta["slots"][k - 1][1],
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
    dirs = sorted(int(x[3:]) for x in os.listdir(os.path.join(ROOT, "problems")) if re.fullmatch(r"set\d+", x))
    for n in dirs:
        meta = set_meta(n)
        probs = [build_problem(n, k, meta) for k in range(1, meta["count"] + 1)]
        total_cases += sum(len(p["cases"]) for p in probs)
        sets.append({"n": n, "label": meta["label"], "title": meta["title"], "sub": meta["sub"], "lead": meta["lead"],
                     "scored": meta.get("scored", True), "outside": meta.get("outside", False), "problems": probs})
        print(f"set{n}: {meta['count']}문제, 테스트 {sum(len(p['cases']) for p in probs)}개")
    data = {"sets": sets, "slots": SLOTS}
    js = "/* tools/build.py 가 problems/ 에서 만든 파일 — 직접 고치지 말고 problems/ 를 고친 뒤 다시 빌드하세요 */\nwindow.BP_PROBLEMS = " + json.dumps(data, ensure_ascii=False) + ";\n"
    out = os.path.join(ROOT, "assets", "problems.js")
    open(out, "w", encoding="utf-8").write(js)
    print(f"→ {out} ({len(js)//1024} KB, 테스트 {total_cases}개)")


if __name__ == "__main__":
    main()
