def grade(score):
    if score >= 90:
        return "A"
    elif score >= 80:
        return "B"
    elif score >= 70:
        return "C"
    else:
        return "F"


# 아래 코드는 수정하지 마세요.
scores = list(map(int, input().split()))
for s in scores:
    print(f"{s} -> {grade(s)}")
