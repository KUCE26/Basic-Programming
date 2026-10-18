name = input()
price = int(input())
rate = int(input())

sale = int(price * (100 - rate) / 100)
print(f"{name}: {sale}원 (정가 {price}원, 할인율 {rate}% 할인)")
