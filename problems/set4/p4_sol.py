n = int(input())
voca = {}
for _ in range(n):
    eng, kor = input().split()
    voca[eng] = kor
m = int(input())
for _ in range(m):
    q = input()
    if q in voca:
        print(voca[q])
    else:
        print("모르는 단어")
print(f"등록된 단어 수: {len(voca)}")
