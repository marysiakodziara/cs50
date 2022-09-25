from cs50 import get_string
from cs50 import get_int

def main():

    n = get_int("the number is: ")
    digits = digits_num(n)
    print(digits)


def digits_num(x):
    k = 1
    while x > 1:
        if x > 10:
            k += 1
        x = x / 10

    return k

def lunhs_algorithm(x):
    


if __name__ == "__main__":
    main()