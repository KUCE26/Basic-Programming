n = int(input())
prices = {}
for _ in range(n):
    name, price = input().split()
    prices[name] = int(price)
query = input()
if query in prices:
    print(prices[query])
else:
    print("없음")
