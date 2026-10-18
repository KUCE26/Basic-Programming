def is_palindrome(word):
    return word == word[::-1]


# 아래 코드는 수정하지 마세요.
n = int(input())
for _ in range(n):
    w = input()
    print(is_palindrome(w))
