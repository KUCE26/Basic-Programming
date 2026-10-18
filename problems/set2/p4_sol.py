check = {}
while True:
    name = input()
    if name == "끝":
        break
    if name in check:
        check[name] += 1
    else:
        check[name] = 1
print(check)
