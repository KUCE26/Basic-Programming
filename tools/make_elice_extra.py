# -*- coding: utf-8 -*-
"""엘리스 12차시 종합 연습 문제(시험 범위 안 10문제) → problems/set7/
   엘리스 11차시 과제 + 12차시 중 모듈·클래스·정규식 문제(시험 범위 밖, 기말 대비) → problems/set8/
문제 문구는 엘리스 원본을 따르고, 자동 채점이 되도록 입력·출력 코드만 붙였다."""
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def write_set(n, meta, problems):
    out = os.path.join(ROOT, "problems", f"set{n}")
    os.makedirs(out, exist_ok=True)
    for f in os.listdir(out):
        os.remove(os.path.join(out, f))
    meta = dict(meta)
    meta["slots"] = [[p[1], p[2]] for p in problems]
    json.dump(meta, open(f"{out}/meta.json", "w", encoding="utf-8"), ensure_ascii=False, indent=1)
    for k, (title, _slot, _lesson, body, sol, tests) in enumerate(problems, 1):
        md = f"# {title}\n{body.strip()}\n"
        open(f"{out}/p{k}_sol.py", "w", encoding="utf-8").write(sol)
        if tests == ["\n"]:
            res = subprocess.run([sys.executable, "-I", f"{out}/p{k}_sol.py"], input="\n", capture_output=True, text=True).stdout.rstrip("\n")
            md = re.sub(r"(## 출력 예시 1\n```\n)(.*?)(```)", lambda m: m.group(1) + res + "\n" + m.group(3), md, flags=re.S)
        open(f"{out}/p{k}.md", "w", encoding="utf-8").write(md)
        open(f"{out}/p{k}_tests.txt", "w", encoding="utf-8").write("=====\n".join(tests))
    print(f"set{n}: {len(problems)}문제 → {out}")


# ──────────────── set7: 12차시 종합 연습 (시험 범위 안) ────────────────
S7 = []
S7.append(("[12차시] 조건에 맞는 암호", "논리·비교 연산", "5차시", """
엘리스 토끼는 다음 조건을 충족하는 암호를 만들려고 합니다. 아래 **1, 2, 3, 4**의 조건을 동시에 충족하는 경우 **또는** **5, 6, 7**의 조건을 동시에 충족하는 경우 `True`를, 아니라면 `False`를 출력합니다.

1. a는 b보다 작거나 같다.
2. a는 d와 같다.
3. b는 c보다 크다.
4. c는 6보다 작다.
5. a는 b와 같다.
6. a는 c와 같다.
7. a는 d와 같다.

## 지시사항
1. 숫자 4개를 공백을 기준으로 입력받으세요. 순서대로 a, b, c, d입니다.
2. 위의 1~4 조건을 동시에 충족하거나 5~7 조건을 동시에 충족하면 `True`, 아니면 `False`를 출력하세요. 논리 연산자(`and`, `or`)와 비교 연산자를 쓰세요.

## 입력 예시 1
```
2 2 2 2
```
## 출력 예시 1
```
True
```

## 입력 예시 2
```
4 6 8 3
```
## 출력 예시 2
```
False
```

## Tips
`a, b, c, d = map(int, input().split())`로 한 번에 받을 수 있어요. `print(조건식)`처럼 조건식의 결과를 바로 출력해도 돼요.
""", """a, b, c, d = map(int, input().split())

if (a <= b and a == d and b > c and c < 6) or (a == b and a == c and a == d):
    print(True)
else:
    print(False)
""", ["2 2 2 2\n", "4 6 8 3\n", "3 5 4 3\n", "3 5 7 3\n", "7 7 7 7\n", "1 2 1 2\n"]))

S7.append(("[12차시] 덧셈 연산", "입력·f-string", "2차시", """
엘리스 토끼는 친구 체셔, 캐터필러와 숫자 놀이를 하고 있습니다. 체셔와 캐터필러가 말한 숫자를 순서대로 더한 값을 빠르게 계산해서 말하는 게임입니다.

## 지시사항
1. 두 줄에 걸쳐 정수 두 개가 입력됩니다.
2. 두 정수를 더한 결과를 `더한 값은 {정수}` 형식으로 출력합니다.

## 입력 예시 1
```
2
7
```
## 출력 예시 1
```
더한 값은 9
```

## 입력 예시 2
```
-3
3
```
## 출력 예시 2
```
더한 값은 0
```
""", """a = int(input())
b = int(input())

print(f"더한 값은 {a + b}")
""", ["2\n7\n", "-3\n3\n", "100\n250\n", "0\n0\n"]))

S7.append(("[12차시] 3호선 역 정보 추출하기", "인덱싱·슬라이싱", "3차시", """
지하철 데이터를 분석하던 중, 2호선과 4호선 역 이름 데이터에 3호선 데이터가 잘못 기입되어 있는 점을 발견했습니다. 2호선 리스트에는 "독립문" 역이, 4호선 리스트에는 "잠원", "대청", "원흥", "삼송" 역이 잘못 들어 있습니다(3호선 역은 `*` 표시). 인덱싱과 슬라이싱으로 잘못 기입된 3호선 역 이름을 추출해 봅시다.

## 지시사항
1. `error_line3`에 `line2`에서 원소 **하나**를 인덱싱으로 가져와 저장하세요.
2. `error_line3_list`에 `line4`에서 리스트의 **일부**를 슬라이싱으로 가져와 저장하세요.
3. 출력 코드는 수정하지 마세요.

## 시작 코드
```python
# 2호선 역 이름 리스트 15개
line2 = ['동대문역사문화공원','신당','상왕십리','왕십리','한양대','뚝섬','성수','건대입구','구의','강변','잠실나루','*독립문',
'까치산','시청','을지로입구']

# 2호선 역 이름 리스트에서 3호선 역 이름 정보를 추출해 보겠습니다(3호선 *표시)
error_line3 = None

# 4호선 역 이름 리스트 15개
line4 = ['충무로','경마공원','쌍문','명동','과천','범계','초지','정부과천청사','안산','오이도','신길온천','*잠원','*대청','*원흥',
'*삼송']

# 4호선 역 이름 리스트에서 3호선 역 이름 정보들을 추출해 보겠습니다(3호선 *표시)
error_line3_list = None


# 아래는 출력 코드입니다. 수정하지 마세요.
print("2호선 리스트에 입력된 3호선 역 이름 정보 :", error_line3)
print("4호선 리스트에 입력된 3호선 역 이름 정보 :", error_line3_list)
```

## 입력 예시 1
```
```
## 출력 예시 1
```
2호선 리스트에 입력된 3호선 역 이름 정보 : *독립문
4호선 리스트에 입력된 3호선 역 이름 정보 : ['*잠원', '*대청', '*원흥', '*삼송']
```

## Tips
인덱스는 0부터 세요. 뒤에서 4개는 `[-4:]`.
""", """line2 = ['동대문역사문화공원','신당','상왕십리','왕십리','한양대','뚝섬','성수','건대입구','구의','강변','잠실나루','*독립문',
'까치산','시청','을지로입구']

error_line3 = line2[11]

line4 = ['충무로','경마공원','쌍문','명동','과천','범계','초지','정부과천청사','안산','오이도','신길온천','*잠원','*대청','*원흥',
'*삼송']

error_line3_list = line4[-4:]

print("2호선 리스트에 입력된 3호선 역 이름 정보 :", error_line3)
print("4호선 리스트에 입력된 3호선 역 이름 정보 :", error_line3_list)
""", ["\n"]))

S7.append(("[12차시] 촉촉한 초코칩", "문자열 count", "4차시", """
친구들과 모여 장기자랑을 하게 된 엘리스 토끼! 비장의 초코칩 랩을 선보이려는데, "촉촉한 초코칩"이라는 말로 라임을 맞췄다고 해요. 이 랩에 "촉촉한 초코칩"이 몇 번 들어 있는지 세어 봅시다.

## 지시사항
1. 임의의 길이의 문자열을 입력받으세요.
2. 입력받은 문자열에 있는 `촉촉한 초코칩`의 횟수만 출력하세요.

## 입력 예시 1
```
난 안 촉촉한 초코칩보다 촉촉한 초코칩이 좋기 때문에 촉촉한 초코칩을 사 먹을 거야
```
## 출력 예시 1
```
3
```

## 입력 예시 2
```
안 촉촉한 초코칩 나라에 살던 안 촉촉한 초코칩이 촉촉한 초코칩 나라의 촉촉한 초코칩을 보고 촉촉한 초코칩이 되고 싶어서 촉촉한 초코칩 나라에 갔는데 촉촉한 초코칩 나라의 문지기가 "넌 촉촉한 초코칩이 아니고 안 촉촉한 초코칩이니까 안 촉촉한 초코칩 나라에서 살아"라고 해서 안 촉촉한 초코칩은 촉촉한 초코칩이 되는 것을 포기하고 안 촉촉한 초코칩 나라로 돌아갔다네
```
## 출력 예시 2
```
13
```

## Tips
`문자열.count("촉촉한 초코칩")` 한 줄이면 됩니다. "안 촉촉한 초코칩"에도 "촉촉한 초코칩"이 들어 있으니 그것도 세요.
""", """rap = input()
print(rap.count('촉촉한 초코칩'))
""", ["난 안 촉촉한 초코칩보다 촉촉한 초코칩이 좋기 때문에 촉촉한 초코칩을 사 먹을 거야\n",
      '안 촉촉한 초코칩 나라에 살던 안 촉촉한 초코칩이 촉촉한 초코칩 나라의 촉촉한 초코칩을 보고 촉촉한 초코칩이 되고 싶어서 촉촉한 초코칩 나라에 갔는데 촉촉한 초코칩 나라의 문지기가 "넌 촉촉한 초코칩이 아니고 안 촉촉한 초코칩이니까 안 촉촉한 초코칩 나라에서 살아"라고 해서 안 촉촉한 초코칩은 촉촉한 초코칩이 되는 것을 포기하고 안 촉촉한 초코칩 나라로 돌아갔다네\n',
      "초코칩\n", "촉촉한 초코칩촉촉한 초코칩\n"]))

S7.append(("[12차시] 과일 가게", "실수 변환·조건문", "5차시", """
엘리스 토끼의 과일 가게에서는 무게로 금액을 책정합니다. 이번에 구매한 과일의 총 무게에 따라 할인해 주는 이벤트를 진행하려고 합니다.

## 지시사항
1. 첫 번째 줄에 구매한 과일 **하나의 무게(kg)**를 실수로 입력받습니다.
2. 두 번째 줄에 구매한 과일의 **개수**를 정수로 입력받습니다.
3. 구매한 과일의 총 무게(무게 × 개수)를 구합니다.
4. 총 무게에 따른 할인 금액을 출력합니다: 10kg 이상 `20000`, 7kg 이상 10kg 미만 `15000`, 3kg 이상 7kg 미만 `10000`, 3kg 미만 `0`.

## 입력 예시 1
```
1.5
5
```
## 출력 예시 1
```
15000
```

## 입력 예시 2
```
0.4
3
```
## 출력 예시 2
```
0
```

## Tips
실수로 바꾸려면 `float(input())`.
""", """weight = float(input())
num = int(input())

total = weight * num

if total >= 10:
    print(20000)
elif total >= 7:
    print(15000)
elif total >= 3:
    print(10000)
else:
    print(0)
""", ["1.5\n5\n", "0.4\n3\n", "2.5\n4\n", "3.0\n1\n", "0.7\n10\n"]))

S7.append(("[12차시] 2의 거듭제곱", "거듭제곱 연산", "2차시", """
엘리스 토끼는 원하는 숫자를 2의 거듭제곱의 지수로 사용하여 계산하는 프로그램을 만들려고 합니다.

## 지시사항
1. 1보다 큰 정수를 한 개 입력받습니다.
2. 입력받은 정수를 2의 지수로 사용하여 2의 거듭제곱을 계산해 출력합니다.

## 입력 예시 1
```
5
```
## 출력 예시 1
```
32
```

## 입력 예시 2
```
10
```
## 출력 예시 2
```
1024
```
""", """n = int(input())
print(2 ** n)
""", ["5\n", "10\n", "2\n", "40\n"]))

S7.append(("[12차시] 날짜 구하기", "문자열 슬라이싱", "4차시", """
엘리스 회사 직원들의 생년월일이 년, 월, 일 순서로 저장되어 있습니다. 년도를 뺀 월과 일을 구하여 생일 날짜에 알림을 띄우려고 합니다.

## 지시사항
1. 첫 번째 줄에 생년월일을 8글자로 입력받습니다.
2. 4글자로 이루어진 년도를 제외한 월일만 출력합니다.

## 입력 예시 1
```
19801005
```
## 출력 예시 1
```
1005
```

## 입력 예시 2
```
20060229
```
## 출력 예시 2
```
0229
```

## Tips
정수로 바꾸면 앞의 0이 사라져요. 문자열 그대로 `[4:]`로 자르세요.
""", """birthday = input()
print(birthday[4:])
""", ["19801005\n", "20060229\n", "20251231\n", "19990101\n"]))

S7.append(("[12차시] 평점 구하기", "함수·sum·f-string", "7차시", """
엘리스 토끼는 쪽지 시험 점수의 합을 구하려고 합니다. 쪽지 시험 총점이 70점 이상인 경우 이수가 가능합니다.

## 지시사항
1. `grade(score)` 함수는 쪽지 시험 점수를 리스트로 받습니다. 쪽지시험 횟수는 과목마다 다릅니다.
2. 총점이 70점 이상이면 `00점으로 이수가 가능합니다.`, 아니면 `00점으로 이수가 불가능합니다.` 문구를 **반환**합니다. (00 자리에 총점)
3. 메인 코드는 수정하지 마세요. 공백으로 구분된 점수들을 입력받아 결과를 출력합니다.

## 시작 코드
```python
def grade(score):
    # 지시사항을 참고하여 코드를 작성하세요.
    pass


# 아래 코드는 수정하지 마세요.
scores = list(map(int, input().split()))
print(grade(scores))
```

## 입력 예시 1
```
12 8 17 13 9 16
```
## 출력 예시 1
```
75점으로 이수가 가능합니다.
```

## 입력 예시 2
```
20 20 20
```
## 출력 예시 2
```
60점으로 이수가 불가능합니다.
```

## Tips
`sum(리스트)`로 합을 구하고, `return f"{total}점으로 ..."`처럼 반환하세요. print가 아니라 return!
""", """def grade(score):
    total = sum(score)
    if total >= 70:
        return f"{total}점으로 이수가 가능합니다."
    else:
        return f"{total}점으로 이수가 불가능합니다."


scores = list(map(int, input().split()))
print(grade(scores))
""", ["12 8 17 13 9 16\n", "20 20 20\n", "70\n", "35 34\n", "10 10 10 10 10 10 10 10\n"]))

S7.append(("[12차시] 소수점 처리하기", "f-string 자릿수", "2·4차시", """
엘리스 토끼에게 필요한 것은 특정 자릿수까지 소수를 반올림하여 출력하는 프로그램입니다. 예를 들어 "1 0.452"를 입력하면 0.5를 출력합니다. `f"{num:.2f}"`처럼 소수점 포맷팅을 쓰면 그 자리 뒤에서 자동으로 반올림됩니다.

## 지시사항
1. 정수와 소수를 공백을 기준으로 입력받습니다. 정수(1~5)는 출력할 소수점 아래 자릿수입니다. 소수의 소수점 아래 자릿수는 정수보다 같거나 큽니다.
2. 입력받은 소수를 소수점 아래 그 자릿수까지 반올림해 `결과는 {소수} 입니다.` 형식으로 출력합니다.

## 입력 예시 1
```
1 0.1234
```
## 출력 예시 1
```
결과는 0.1 입니다.
```

## 입력 예시 2
```
2 2.567
```
## 출력 예시 2
```
결과는 2.57 입니다.
```

## Tips
자릿수가 변수 n이면 `f"{m:.{n}f}"`처럼 중괄호를 겹쳐 쓸 수 있어요.
""", """n, m = input().split()
n = int(n)
m = float(m)
print(f"결과는 {m:.{n}f} 입니다.")
""", ["1 0.1234\n", "2 2.567\n", "3 3.14159\n", "5 0.123456\n", "1 9.96\n"]))

S7.append(("[12차시] 디버깅 문제: 문자열 덧셈", "for·str 변환", "6차시", """
"엥? 왜 오류가 나는거지?" 연구실에서 근무하는 박00씨는 실험 결과값을 `결과1.txt, 결과2.txt, 결과3.txt …`로 정리하려다 오류를 만났습니다. 시작 코드의 오류를 찾아 고쳐 봅시다.

## 지시사항
1. 실험 데이터 출력 파일의 양을 나타내는 양의 정수 n이 입력됩니다.
2. 다음 n줄에 걸쳐 각각 올바르게 파일명을 출력하세요.
3. 시작 코드를 실행해 에러 메시지(TypeError)를 읽고, 어디를 고쳐야 하는지 찾으세요.

## 시작 코드
```python
n = int(input())

for i in range(1, n + 1):
    print("결과" + i + ".txt")
```

## 입력 예시 1
```
5
```
## 출력 예시 1
```
결과1.txt
결과2.txt
결과3.txt
결과4.txt
결과5.txt
```

## 입력 예시 2
```
1
```
## 출력 예시 2
```
결과1.txt
```

## Tips
문자열과 정수는 `+`로 이을 수 없어요. `str(i)`로 바꾸거나 f-string을 쓰세요.
""", """n = int(input())

for i in range(1, n + 1):
    print("결과" + str(i) + ".txt")
""", ["5\n", "1\n", "12\n", "3\n"]))

# ──────────────── set8: 11차시 과제 + 12차시 범위 밖 ────────────────
S8 = []
S8.append(("[11차시 과제2] 지구의 부피", "math 모듈", "9차시", """
우리가 살고 있는 지구의 반지름은 약 6,371km입니다. 지구는 둥근 구의 형태이므로 구의 부피 공식 **V = 4/3 · π · r³**으로 지구의 부피를 대략 계산할 수 있습니다.

## 지시사항
1. `math` 모듈을 불러오세요.
2. 구의 부피 공식으로 지구의 부피를 계산해 `volume` 변수에 저장하세요. 반지름은 6371, 파이값은 `math.pi`를 쓰세요. 식은 `4 / 3 * math.pi * 6371 ** 3` 순서로 계산하세요.
3. 출력 코드는 수정하지 마세요.

## 시작 코드
```python
# 1번을 해보세요.


# 2번을 해보세요.
volume = None

# 계산을 잘 했는지 확인해 보세요! 수정하지 마세요.
print(volume)
```

## 입력 예시 1
```
```
## 출력 예시 1
```
```

## Tips
`import math` 뒤에 `math.pi`로 접근합니다. 실수 계산은 식의 순서에 따라 마지막 자리가 달라질 수 있으니 지시사항의 식 그대로 쓰세요.
""", """import math

volume = 4 / 3 * math.pi * 6371 ** 3

print(volume)
""", ["\n"]))

S8.append(("[11차시 과제3] 붕어빵 만들기", "클래스·인스턴스", "11차시", """
붕어빵을 만드는 틀(클래스)이 있다면 이로부터 붕어빵(인스턴스)을 만들 수 있습니다. 붕어빵 클래스를 만들고, 팥 붕어빵과 슈크림 붕어빵을 만들어 봅시다.

## 지시사항
1. 클래스 `Bbread`를 만들고, 클래스 변수 `taste`에 `"밀가루"`를 대입하세요.
2. 메서드 `eat(self)`를 만드세요. `taste`와 `"맛이 나요!"`를 `print(self.taste, "맛이 나요!")`처럼 출력합니다.
3. `Bbread`의 인스턴스 `redBean`과 `choux`를 만드세요.
4. `redBean.taste`를 `"팥"`으로, `choux.taste`를 `"슈크림"`으로 바꾸세요.
5. `redBean.eat()`, `choux.eat()`을 차례로 실행하세요.

## 시작 코드
```python
# 클래스 Bbread(붕어빵)을 만들어봅시다.
# Bbread의 클래스 변수 taste를 생성하고, "밀가루"를 대입해봅시다.
# Bbread의 메서드 eat()를 생성해봅시다. 이 메서드는 taste, "맛이 나요!"를 출력합니다.


# 클래스 Bbread의 인스턴스 redBean과 choux를 만들어봅시다.


# 객체 redBean의 클래스 변수 taste를 "팥"으로 바꿔줍시다


# 객체 choux의 클래스 변수 taste를 "슈크림"으로 바꿔줍시다


# 객체 redBean의 메서드 eat()를 실행해봅시다


# 객체 choux의 메서드 eat()를 실행해봅시다

```

## 입력 예시 1
```
```
## 출력 예시 1
```
팥 맛이 나요!
슈크림 맛이 나요!
```

## Tips
메서드 안에서 그 객체의 변수를 쓸 땐 `self.taste`처럼 `self`를 붙여요.
""", """class Bbread:
    taste = '밀가루'

    def eat(self):
        print(self.taste, '맛이 나요!')


redBean = Bbread()
choux = Bbread()

redBean.taste = '팥'
choux.taste = '슈크림'

redBean.eat()
choux.eat()
""", ["\n"]))

S8.append(("[11차시 과제4] zip()", "zip·튜플", "11차시", """
여러 개의 iterable 객체를 묶어 주는 `zip()`은 같은 인덱스의 값들을 튜플로 묶어 줍니다. `list(zip([1, 2], ['a', 'b']))`는 `[(1, 'a'), (2, 'b')]`입니다.

## 지시사항
1. `first_name`을 첫 번째 요소, `last_name`을 두 번째 요소로 가지는 튜플을 `zip()`으로 만드세요.
2. 만든 튜플을 한 줄씩 출력하세요.

## 시작 코드
```python
def main():
    first_name = ['elice', 'mad', 'cheshire', 'dodo', 'heart']
    last_name = ['rabbit', 'hatter', 'cat', 'bird', 'queen']

    # first_name을 첫 번째 요소, last_name을 두 번째 요소로 가지는 튜플을 출력하세요.



if __name__ == "__main__":
    main()
```

## 입력 예시 1
```
```
## 출력 예시 1
```
('elice', 'rabbit')
('mad', 'hatter')
('cheshire', 'cat')
('dodo', 'bird')
('heart', 'queen')
```

## Tips
`for pair in zip(first_name, last_name): print(pair)`
""", """def main():
    first_name = ['elice', 'mad', 'cheshire', 'dodo', 'heart']
    last_name = ['rabbit', 'hatter', 'cat', 'bird', 'queen']

    for pair in zip(first_name, last_name):
        print(pair)


if __name__ == "__main__":
    main()
""", ["\n"]))

S8.append(("[11차시 과제5] itertools 라이브러리", "itertools·이터레이터", "11차시", """
파이썬 내장 라이브러리 `itertools`로 쉽게 iterator를 만들 수 있습니다. `count()`는 무한히 이어지는 숫자, `repeat('test')`는 반복되는 값, `combinations([1, 2, 3], 2)`는 조합을 만듭니다.

## 지시사항
1. `itertools` 라이브러리를 불러오세요.
2. `3 3 3`을 멤버로 가지는 iterator를 생성하세요. (`itertools.repeat(3, 3)` 또는 `iter([3, 3, 3])`)
3. 생성한 iterator의 값을 누적한 iterator를 `itertools.accumulate()`로 만드세요. (3, 6, 9)
4. 누적한 iterator에서 **중복에 상관없이 순서에 상관 있게** 3개씩 뽑아(`itertools.permutations(..., 3)`) 한 줄에 하나씩 출력하세요.

## 시작 코드
```python
# itertools 라이브러리를 불러오세요.


def main():
    # `3 3 3` 을 멤버로 가지는 iterator를 생성하세요.
    x = None

    # 생성한 iterator의 값을 누적한 iterator를 생성하세요.
    y = None

    # 누적한 iterator에서 중복에 상관 없이 순서에 상관 있게 3개씩 출력하세요.


if __name__ == "__main__":
    main()
```

## 입력 예시 1
```
```
## 출력 예시 1
```
(3, 6, 9)
(3, 9, 6)
(6, 3, 9)
(6, 9, 3)
(9, 3, 6)
(9, 6, 3)
```

## Tips
`print(*itertools.permutations(y, 3), sep='\\n')`처럼 한 번에 출력하거나 for로 돌리세요.
""", """import itertools


def main():
    x = itertools.repeat(3, 3)
    y = itertools.accumulate(x)
    for p in itertools.permutations(y, 3):
        print(p)


if __name__ == "__main__":
    main()
""", ["\n"]))

S8.append(("[11차시 과제6] 여러 조건 나타내기", "정규표현식 |", "11차시", """
문자열에서 여러 가지 문자열을 동시에 검색하고 싶다면 정규표현식의 'or 연산자' `|`를 씁니다.

## 지시사항
1. 문자열 `"I like apple and banana"`에 대해 `p1`, `p2`에는 각각 apple과 banana를 검색하는 정규표현식이 있습니다.
2. 변수 `p3`에 apple과 banana를 **동시에** 검색할 수 있는 정규표현식을 작성하세요.
3. 나머지 코드는 수정하지 마세요.

## 시작 코드
```python
import re

p1 = "apple"        # apple 포함하면 매치
p2 = "banana"       # banana 포함하면 매치

m1 = re.findall(p1, "I like apple and banana")
m2 = re.findall(p2, "I like apple and banana")

print("m1 결과 : ", m1)
print("m2 결과 : ", m2)


### 아래 p3에 직접 정규표현식을 입력해보세요!

p3 = None             # apple 또는 banana가 포함되면 매치

m3 = re.findall(p3, "I like apple and banana")

print("m3 결과 : ", m3)
```

## 입력 예시 1
```
```
## 출력 예시 1
```
m1 결과 :  ['apple']
m2 결과 :  ['banana']
m3 결과 :  ['apple', 'banana']
```
""", """import re

p1 = "apple"
p2 = "banana"

m1 = re.findall(p1, "I like apple and banana")
m2 = re.findall(p2, "I like apple and banana")

print("m1 결과 : ", m1)
print("m2 결과 : ", m2)

p3 = "apple|banana"

m3 = re.findall(p3, "I like apple and banana")

print("m3 결과 : ", m3)
""", ["\n"]))

S8.append(("[11차시 과제7] 임의의 문자 찾기", "정규표현식 \\w", "11차시", r"""
정규표현식 `[A-Za-z0-9_]`은 알파벳 대소문자, 숫자, 밑줄(_)을 매칭하는 패턴이고, 같은 뜻의 메타 문자가 `\w`입니다. `\W`는 `[^A-Za-z0-9_]`와 같이 그 반대입니다.

## 지시사항
1. 문자열 `"el_ice%20$19"`에 대해 `p1`에는 알파벳 대소문자·숫자·밑줄을 매칭하는 정규표현식을, `p2`에는 그 반대 조건의 정규표현식을 작성하세요.
2. 나머지 코드는 수정하지 마세요.

## 시작 코드
```python
import re

'''
아래에 정규표현식을 직접 입력해보세요!
'''

p1 = None         # 알파벳 대소문자, 숫자, 밑줄만 매치
p2 = None         # 그 반대

m1 = re.findall(p1, "el_ice%20$19")
m2 = re.findall(p2, "el_ice%20$19")

print("m1 결과 : ", m1)
print("m2 결과 : ", m2)
```

## 입력 예시 1
```
```
## 출력 예시 1
```
m1 결과 :  ['e', 'l', '_', 'i', 'c', 'e', '2', '0', '1', '9']
m2 결과 :  ['%', '$']
```

## Tips
역슬래시가 들어가는 패턴은 `r"\w"`처럼 raw 문자열로 쓰는 습관을 들이세요.
""", r"""import re

p1 = r"\w"
p2 = r"\W"

m1 = re.findall(p1, "el_ice%20$19")
m2 = re.findall(p2, "el_ice%20$19")

print("m1 결과 : ", m1)
print("m2 결과 : ", m2)
""", ["\n"]))

S8.append(("[12차시] 임의의 숫자 찾기", "정규표현식 \\d", "11차시", r"""
`[0-9]`와 같은 의미의 메타 문자 `\d`는 모든 숫자 문자에 매칭하고, `\D`는 숫자가 아닌 문자(`[^0-9]`)에 매칭합니다.

## 지시사항
1. 문자열 `"el_ice%20$19"`에 대해 `p1`에는 숫자를, `p2`에는 숫자가 아닌 문자를 검색하는 정규표현식을 작성하세요.
2. 나머지 코드는 수정하지 마세요.

## 시작 코드
```python
import re

'''
아래에 정규표현식을 직접 입력해보세요!
'''

p1 = None         # 숫자만 매치
p2 = None         # 숫자가 아니면 매치

m1 = re.findall(p1, "el_ice%20$19")
m2 = re.findall(p2, "el_ice%20$19")

print("m1 결과 : ", m1)
print("m2 결과 : ", m2)
```

## 입력 예시 1
```
```
## 출력 예시 1
```
m1 결과 :  ['2', '0', '1', '9']
m2 결과 :  ['e', 'l', '_', 'i', 'c', 'e', '%', '$']
```
""", r"""import re

p1 = r"\d"
p2 = r"\D"

m1 = re.findall(p1, "el_ice%20$19")
m2 = re.findall(p2, "el_ice%20$19")

print("m1 결과 : ", m1)
print("m2 결과 : ", m2)
""", ["\n"]))

S8.append(("[12차시] 직사각형 넓이", "클래스·메서드", "11차시", """
다양한 직사각형의 가로와 세로 길이를 입력받아 넓이를 구하려고 합니다. 클래스 `Rectangle`의 빈칸 `None`을 채우세요.

## 지시사항
1. `__init__(self, w, h)`: 인스턴스 변수 `width`에 w, `height`에 h를 저장하세요.
2. `get_info(self)`: `가로 길이: 10, 세로 길이: 20` 형식의 문자열을 **반환**하세요.
3. `get_area(self)`: 넓이(가로 × 세로)를 `직사각형의 넓이: 200` 형식의 문자열로 **반환**하세요.
4. 메인 코드는 수정하지 마세요. 가로, 세로를 한 줄씩 입력받습니다.

## 시작 코드
```python
class Rectangle:
    def __init__(self, w, h):
        self.width = None
        self.height = None

    def get_info(self):
        return None

    def get_area(self):
        return None


# 아래 코드는 수정하지 마세요.
w = int(input())
h = int(input())
rect = Rectangle(w, h)
print(rect.get_info())
print(rect.get_area())
```

## 입력 예시 1
```
5
8
```
## 출력 예시 1
```
가로 길이: 5, 세로 길이: 8
직사각형의 넓이: 40
```

## 입력 예시 2
```
10
20
```
## 출력 예시 2
```
가로 길이: 10, 세로 길이: 20
직사각형의 넓이: 200
```
""", """class Rectangle:
    def __init__(self, w, h):
        self.width = w
        self.height = h

    def get_info(self):
        return f"가로 길이: {self.width}, 세로 길이: {self.height}"

    def get_area(self):
        return f"직사각형의 넓이: {self.width * self.height}"


w = int(input())
h = int(input())
rect = Rectangle(w, h)
print(rect.get_info())
print(rect.get_area())
""", ["5\n8\n", "10\n20\n", "1\n1\n", "7\n3\n"]))


write_set(7, {"label": "연습", "title": "12차시 종합 연습", "sub": "엘리스 12차시 종합 연습 문제 중 시험 범위(2~8차시) 안 10문제",
              "lead": "교수님이 종합 연습으로 올린 문제 중 모듈·클래스·정규식 없이 풀 수 있는 것만 모았어요", "scored": False}, S7)
write_set(8, {"label": "범위밖", "title": "11차시 과제 · 범위 밖", "sub": "모듈·클래스·정규식 8문제 (중간고사 범위 밖, 기말 대비)",
              "lead": "11차시 과제와 12차시 연습 중 import·class·re 가 필요한 문제. 중간고사엔 안 나오니 시간이 남을 때만", "scored": False, "outside": True}, S8)
