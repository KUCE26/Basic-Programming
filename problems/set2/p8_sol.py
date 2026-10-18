balance = int(input())
while True:
    money = int(input())
    if money == 0:
        break
    if balance + money < 0:
        print("잔액 부족")
        continue
    balance += money
print(f"최종 잔액: {balance}원")
