import itertools


def main():
    x = itertools.repeat(3, 3)
    y = itertools.accumulate(x)
    for p in itertools.permutations(y, 3):
        print(p)


if __name__ == "__main__":
    main()
