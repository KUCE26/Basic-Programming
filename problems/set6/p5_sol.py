foods = input().split()

result = ('치즈' in foods and '달걀' in foods) or \
         ('고구마' in foods and '김치' in foods) or \
         ('감자' in foods and '토마토' in foods)

print(result)
