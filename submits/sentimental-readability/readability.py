# TODO

from sc50 import get_string

def main():
    text1 = get_string("Write text sample: ")
    


def count_letters(text):
    n = len(text)
    letters = 0
    for i in range(n):
        if isupper(text[i]):
            letters += 1
        if islower(text[i]):
            letters += 1
    return letters


if __name__ == "__main__":
    main()