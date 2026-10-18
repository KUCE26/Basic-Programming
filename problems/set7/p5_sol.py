weight = float(input())
num = int(input())

total = weight * num

if total >= 10:
    print(20000)
elif total >= 7:
    print(15000)
elif total >= 3:
    print(10000)
else:
    print(0)
