at_bat = int(input())
hit = int(input())

rate = (6 + hit) / (16 + at_bat)
n = int(rate * 1000)
hal = n // 100
pun = n // 10 % 10
ri = n % 10

if hal != 0:
    print("%d할" % hal)
if pun != 0:
    print("%d푼" % pun)
if ri != 0:
    print("%d리" % ri)
