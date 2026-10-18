d = int(input())
fare = 4800
if d > 2000:
    extra = d - 2000
    units = extra // 131
    if extra % 131 != 0:
        units += 1
    fare += units * 100
print(f"택시 요금은 {fare}원입니다.")
