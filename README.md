# Basic-Programming

고려대학교 **기초프로그래밍** 대비 사이트예요. 엘리스 실습과 같은 형식(지시사항 → 코드 작성 → 실행/제출 → 테스트케이스 채점)으로 브라우저에서 바로 풀 수 있어요. 대시보드에서 세 트랙 중 하나를 고르면 그 트랙의 세트가 나와요.

| 트랙 | 언어 | 세트 |
|---|---|---|
| **중간고사** | Python (Pyodide, 브라우저 안 실행) | 모의테스트 A–E 50문제 · 엘리스 4·8차시 과제 15 · 12차시 연습 10 · 범위 밖 8 |
| **기말고사** | C (godbolt.org 에서 gcc 컴파일) | C1 기본 16 · C2 응용 16 · C3 심화 10 — 엘리스 13·14·17·18차시. 새 차시가 올라오면 추가 |
| **코딩테스트** | C++ (godbolt.org 에서 g++ 컴파일) | C++ 워밍업 8 + SWEA 방학특강 35문제 다시 풀기 로드맵(체크 저장) |

사이트 주소 (GitHub Pages): https://kuce26.github.io/Basic-Programming/

C·C++ 은 브라우저 안에서 컴파일할 수 없어서, 실행·제출할 때 코드와 입력을 [Compiler Explorer](https://godbolt.org) 공개 API 로 보내 결과를 받아요 (C `gcc -std=c11 -O0`, C++ `g++ -std=c++17 -O2`). 테스트 하나에 2~4초, 최대 3개 동시 실행.

## 페이지

| 파일 | 내용 |
|---|---|
| `index.html?track=mid·final·ct` | 대시보드 — 트랙 선택, 세트 카드, 세트별 통과 수, 트랙별 안내. 코테 트랙엔 SWEA 로드맵 체크리스트 |
| `practice.html?set=N&q=K` | 실습 — 왼쪽 문제(지시사항·입출력 예시·Tips), 오른쪽 편집기(Ace) + 실행/제출. 실행은 `입력` 탭 내용으로, 제출은 숨겨진 테스트 전부(문제당 4~6개)로 채점. 통과 기록과 작성 중 코드는 이 브라우저(localStorage)에만 저장 |

## 범위와 구성 (중간고사 트랙)

- 범위: 엘리스 「기초 프로그래밍」 **2~8차시** (Python 시작하기 · 자료형 · 조건문 · 반복문 · 함수 1·2). 모듈·예외 처리·클래스는 쓰지 않아요.
- 난이도: 4차시·8차시 과제 수준. 문제 유형은 고려대 엘리스 실습·과제와 엘리스 아카데미 「Do it! 첫 파이썬」을 참고해 새로 만든 변형 문제예요.
- 세트마다 같은 10슬롯: 1 입출력·산술 · 2 포맷팅·형 변환 · 3 리스트 · 4 딕셔너리 · 5 문자열 · 6 조건문 · 7 for 반복 · 8 while·break · 9 함수 · 10 함수 심화
- 채점 규칙: 줄 끝 공백과 맨 끝 빈 줄만 무시하고 글자 하나까지 비교(엘리스·`check.py`와 같음). 5초 넘게 돌면 시간 초과.

## 배포

GitHub Pages: **Settings → Pages → Build and deployment → Source: Deploy from a branch → Branch: `main` / `(root)` → Save**.
빌드 도구가 필요 없는 정적 사이트라 push하면 바로 반영돼요. (`.nojekyll` 포함)

## 문제 수정·추가

문제 원본은 `problems/setN/`에 문제마다 세 파일이에요. 세트 정보는 `setN/meta.json` — `label·title·sub·lead·slots` 에 더해 **`track`**(mid·final·ct), **`lang`**(python·c·cpp), **`level`**(기말 1~3) 을 둬요. meta.json 이 없는 set1~5 는 중간고사 Python 세트. (`set6`은 엘리스 4·8차시 과제 — `tools/make_elice_set.py`, `set7`·`set8`은 12차시 연습·11차시 과제 — `tools/make_elice_extra.py`가 만들어요.)

| 파일 | 내용 |
|---|---|
| `pK.md` | 제목, 스토리, `## 지시사항`, `## 시작 코드`(C/C++은 필수), `## 입력 예시 n` / `## 출력 예시 n`, `## Tips` |
| `pK_sol.py` / `pK_sol.c` / `pK_sol.cpp` | 모범 답안 (표준 입력 → 표준 출력). C/C++ 은 `-Wall` 경고 없이 |
| `pK_tests.txt` | 채점용 입력 4~6개, `=====` 한 줄로 구분. 앞 두 개는 입력 예시와 같게 |

```bash
python3 tools/build.py        # 모든 세트: 모범 답안을 테스트로 실행(언어별 컴파일은 tools/langs.py)해 기대 출력 생성, md 예시와 대조 → assets/problems.js
python3 tools/verify.py 10    # 10세트만 빠르게 검사 (예시 일치, 범위 금지 문법, 테스트 수)
```

**기말 트랙에 새 차시 문제 추가하기** — 엘리스에 새 차시(19차시~)가 올라오면 그 범위의 변형 문제를 난이도에 따라 `set9`(Lv1)·`set10`(Lv2)·`set11`(Lv3) 에 `p9.md …` 로 이어 붙이고 `meta.json` 의 `slots` 에 한 줄씩 추가한 뒤 빌드하면 돼요. 포인터·배열처럼 범위가 크게 바뀌는 주부터는 `set13+` 로 새 세트를 만들어요(`track: "final"`). 마지막으로 반영한 엘리스 차시 번호는 `problems/elice_state.json` 의 `last_lecture` 에 적어 두어요(주간 자동 작업이 이 값보다 큰 차시만 추가해요).
