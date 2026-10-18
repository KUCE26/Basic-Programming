def validate_email(email):
    if email.count('@') != 1:
        return False

    domain = email.split('@')[1]

    if domain.count('.') < 1:
        return False

    parts = domain.split(".")
    for part in parts:
        if part == "":
            return False

    return True


n = int(input())
for _ in range(n):
    print(validate_email(input()))
