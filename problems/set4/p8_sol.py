budget = int(input())
total = 0
count = 0
while True:
    price = int(input())
    if total + price > budget:
        print("예산 초과")
        break
    total += price
    count += 1
print(f"산 물건: {count}개")
print(f"남은 돈: {budget - total}원")
