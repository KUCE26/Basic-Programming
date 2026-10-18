day = int(input())
match day:
    case 1:
        print("월요일")
    case 2:
        print("화요일")
    case 3:
        print("수요일")
    case 4:
        print("목요일")
    case 5:
        print("금요일")
    case 6:
        print("토요일")
        print("주말")
    case 7:
        print("일요일")
        print("주말")
    case _:
        print("잘못된 입력")
