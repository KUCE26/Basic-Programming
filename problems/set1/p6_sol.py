temp = float(input())
if temp >= 37.5:
    print("고열")
elif temp >= 37.0:
    print("미열")
elif temp < 36.0:
    print("저체온")
else:
    print("정상")
