n = int(input())
scores = {}
for _ in range(n):
    name, score = input().split()
    scores[name] = int(score)
passed = []
for name, score in scores.items():
    if score >= 80:
        passed.append(name)
if len(passed) == 0:
    print("없음")
else:
    print(" ".join(passed))
