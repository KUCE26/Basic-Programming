height = int(input())
age = int(input())

if height >= 140 and age >= 8:
    print("탑승 가능")
elif age >= 8:
    print("키 제한")
elif height >= 140:
    print("나이 제한")
else:
    print("탑승 불가")
