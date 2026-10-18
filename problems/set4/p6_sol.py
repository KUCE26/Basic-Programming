a, b, c = map(int, input().split())
longest = max(a, b, c)
rest = a + b + c - longest
if longest >= rest:
    print("삼각형이 아닙니다.")
elif a == b == c:
    print("정삼각형입니다.")
elif a == b or b == c or a == c:
    print("이등변삼각형입니다.")
else:
    print("일반삼각형입니다.")
