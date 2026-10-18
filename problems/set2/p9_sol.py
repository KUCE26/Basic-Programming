def count_vowels(text):
    count = 0
    for ch in text.lower():
        if ch in "aeiou":
            count += 1
    return count


# 아래 코드는 수정하지 마세요.
text = input()
print(f"모음 개수: {count_vowels(text)}")
