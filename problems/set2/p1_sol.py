sec = int(input())
h = sec // 3600
m = sec % 3600 // 60
s = sec % 60
print(f"{h}시간 {m}분 {s}초")
