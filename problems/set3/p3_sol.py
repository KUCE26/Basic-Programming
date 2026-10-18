stock = list(map(int, input().split()))
while 0 in stock:
    stock.remove(0)
print(stock)
print(f"개수: {len(stock)}")
print(f"최솟값: {min(stock)}, 최댓값: {max(stock)}")
