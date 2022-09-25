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
        if text[i].isalpha():
            letters += 1
    return letters

def count_words(text):
    n = len(text)
    words = 1
    for i in range(n):
        if text[i] == ' ':
            words += 1
    return words


if __name__ == "__main__":
    main()