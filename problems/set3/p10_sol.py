def make_profile(name, age, **extra):
    print(f"이름: {name}, 나이: {age}")
    for key, value in extra.items():
        print(f"{key} = {value}")


# 아래 코드는 수정하지 마세요.
name, age = input().split()
age = int(age)
extra = {}
for pair in input().split():
    key, value = pair.split("=")
    extra[key] = value
make_profile(name, age, **extra)
