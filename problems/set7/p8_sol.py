def grade(score):
    total = sum(score)
    if total >= 70:
        return f"{total}점으로 이수가 가능합니다."
    else:
        return f"{total}점으로 이수가 불가능합니다."


scores = list(map(int, input().split()))
print(grade(scores))
