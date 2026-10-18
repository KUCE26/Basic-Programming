won = int(input())
rate = float(input())
usd = won / rate
print("환율: %.1f원" % rate)
print("%d원은 %.2f달러입니다." % (won, usd))
