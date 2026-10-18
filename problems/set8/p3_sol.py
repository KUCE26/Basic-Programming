def main():
    first_name = ['elice', 'mad', 'cheshire', 'dodo', 'heart']
    last_name = ['rabbit', 'hatter', 'cat', 'bird', 'queen']

    for pair in zip(first_name, last_name):
        print(pair)


if __name__ == "__main__":
    main()
