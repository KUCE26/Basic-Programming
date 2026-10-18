price = int(input())
count = int(input())
paid = int(input())
total = price * count
print(f"합계: {total}원")
print(f"거스름돈: {paid - total}원")
