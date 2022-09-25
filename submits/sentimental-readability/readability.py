# TODO

from cs50 import get_string

def main():
    text1 = get_string("Write text sample: ")
    letters = count_letters(text1)
    words = count_words(text1)
    sentences = count_sentences(text1)
    print(letters, words, sentences)
    L = letters * 100 / words
    S = sentences / words * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)
    if index > 16:
        print("Grade 16+\n")
    elif index < 1:
        print("Before Grade 1\n")
    else:
        print(f"Grade {index}\n")


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

def count_sentences(text):
    n = len(text)
    sentence = 0
    for i in range(n):
        if text[i] == '.':
            sentence += 1
        elif text[i] == '!':
            sentence += 1
        elif text[i] == '?':
            sentence += 1
    return sentence

if __name__ == "__main__":
    main()