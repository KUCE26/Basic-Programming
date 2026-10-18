def clean_name(name):
    name = name.strip()
    return name[0].upper() + name[1:].lower()


# 아래 코드는 수정하지 마세요.
n = int(input())
for _ in range(n):
    print(clean_name(input()))
