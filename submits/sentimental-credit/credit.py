from cs50 import get_string
from cs50 import get_int

def main():

    n = get_int("the number is: ")
    digits = digits_num(n)
    validation = lunhs_algorithm(n)
    print(digits, validation)
    answer(n, digits, validation)


def digits_num(x):
    k = 1
    while x > 1:
        if x > 10:
            k += 1
        x = int(x / 10)

    return k

def lunhs_algorithm(x):
    sum = 0
    while x > 0:
        every_other = int((2 * ((x / 10) - ((x / 100) * 10))))
        remaining_numb = int((x - ((x / 10) * 10)))
        prod_digits = 0
        if every_other > 9:
            prod_digits = int((every_other / 10) + (every_other - ((every_other / 10) * 10)))
        else :
            prod_digits = int(every_other)

        sum = int(sum + prod_digits + remaining_numb)
        x = int(x / 100)

    if sum % 10 == 0:
        return 1
    else:
        return 0


def answer(x, k, y):
    start_num = 0
    while x > 99:
        x = int(x / 10)
        start_num = x

    if start_num / 10 == 4:
        start_num = 4

    print(start_num)
    if start_num == 4 and ((k == 13 or k == 16) and y == 1):
        print("VISA\n")
    elif ((start_num == 34 or start_num == 37) and k == 15 and y == 1):
        print("AMEX\n")
    elif ((start_num == 51 or start_num == 52 or start_num == 53 or start_num == 54 or start_num == 55) and k == 16 and y == 1):
        print("MASTERCARD\n")
    else:
        print("INVALID\n")


if __name__ == "__main__":
    main()