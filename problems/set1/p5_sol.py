email = input()
parts = email.split('@')
user = parts[0]
domain = parts[1]
print(f"아이디: {user}")
print(f"도메인: {domain}")
print(f"점 개수: {domain.count('.')}")
print(f"대문자: {email.upper()}")
