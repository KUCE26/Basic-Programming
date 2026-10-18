answer = int(input())
count = 0
while True:
    guess = int(input())
    count += 1
    if guess < answer:
        print("UP")
    elif guess > answer:
        print("DOWN")
    else:
        print(f"정답! {count}번 만에 맞혔습니다")
        break
