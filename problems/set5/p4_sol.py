names = input().split()

votes = {}
for n in names:
    if n in votes:
        votes[n] += 1
    else:
        votes[n] = 1
print(votes)

best_name = ""
best_count = 0
for n, c in votes.items():
    if c > best_count:
        best_name = n
        best_count = c
print(f"당선: {best_name}")
