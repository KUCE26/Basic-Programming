count = 0
longest = ""
while True:
    word = input()
    if word == "end":
        break
    count += 1
    if len(word) > len(longest):
        longest = word
print(f"단어 개수: {count}")
print(f"가장 긴 단어: {longest}")
