n = int(input())
odds = []
for i in range(1, n + 1):
    if i % 2 == 1:
        odds.append(i)
print(*odds)
print(f"홀수의 합: {sum(odds)}")
