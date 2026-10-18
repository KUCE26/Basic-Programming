N = int(input())

count = 0
for i in range(1, N + 1):
    if N % i == 0:
        print(i, end=" ")
        count += 1
        if count % 10 == 0:
            print()
