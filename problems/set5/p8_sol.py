n = int(input())

total = 0
biggest = 0
i = 0
while i < n:
    pay = int(input())
    total += pay
    if pay > biggest:
        biggest = pay
    i += 1

print(f"총액: {total}")
print(f"1인당 부담액: {total // n}")
print(f"가장 많이 낸 금액: {biggest}")
