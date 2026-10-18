"""Validate a set: run solutions on tests, compare md examples, lint syntax, build expected outputs."""
import json, os, re, subprocess, sys

BASE = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "problems")
BANNED = re.compile(r"^\s*(import |from \S+ import|try:|except\b|class |with open|open\()", re.M)


def norm(s):
    return "\n".join(l.rstrip() for l in s.rstrip("\n").split("\n"))


def run(path, inp):
    r = subprocess.run([sys.executable, path], input=inp, capture_output=True, text=True, timeout=5)
    return norm(r.stdout), r.stderr.strip().splitlines()[-1] if r.returncode else ""


def examples(md):
    ins = re.findall(r"## 입력 예시 \d+\s*\n```\n?(.*?)```", md, re.S)
    outs = re.findall(r"## 출력 예시 \d+\s*\n```\n?(.*?)```", md, re.S)
    return [i if i.endswith("\n") else i + "\n" for i in ins], [norm(o) for o in outs]


def check_set(n):
    d = os.path.join(BASE, f"set{n}")
    problems = {}
    issues = []
    for k in range(1, 11):
        md = open(f"{d}/p{k}.md", encoding="utf-8").read()
        sol = f"{d}/p{k}_sol.py"
        src = open(sol, encoding="utf-8").read()
        if BANNED.search(src):
            issues.append(f"set{n} p{k}: banned construct in solution: {BANNED.search(src).group(0).strip()}")
        tests = [t if t.endswith("\n") else t + "\n" for t in open(f"{d}/p{k}_tests.txt", encoding="utf-8").read().split("=====\n")]
        tests = [t for t in tests if t.strip()]
        ins, outs = examples(md)
        if len(ins) != len(outs) or not ins:
            issues.append(f"set{n} p{k}: example count mismatch {len(ins)} in / {len(outs)} out")
        for i, (inp, exp) in enumerate(zip(ins, outs), 1):
            out, err = run(sol, inp)
            if err or out != exp:
                issues.append(f"set{n} p{k}: example {i} mismatch\n  expected: {exp!r}\n  got:      {out!r} {err}")
        cases = []
        for t in tests:
            out, err = run(sol, t)
            if err:
                issues.append(f"set{n} p{k}: test error on {t!r}: {err}")
            cases.append([t, out])
        if len(cases) < 4:
            issues.append(f"set{n} p{k}: only {len(cases)} tests")
        title = md.split("\n", 1)[0].lstrip("# ").strip()
        problems[k] = {"title": title, "cases": cases}
    return problems, issues


if __name__ == "__main__":
    n = sys.argv[1]
    problems, issues = check_set(n)
    json.dump(problems, open(os.path.join(BASE, f"set{n}", "cases.json"), "w", encoding="utf-8"), ensure_ascii=False, indent=1)
    print(f"set{n}: {len(issues)} issues")
    for i in issues:
        print(" -", i)
    for k, p in problems.items():
        print(f"  p{k} {p['title']} ({len(p['cases'])} tests)")
