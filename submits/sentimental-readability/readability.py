# TODO

from cs50 import get_string

def main():
    text1 = get_string("Write text sample: ")
    letters = count_letters(text1)
    print(letters)


def count_letters(text):
    n = len(text)
    letters = 0
    for i in range(n):
        if Isalpha(text[i]):
            letters += 1
    return letters


if __name__ == "__main__":
    main()