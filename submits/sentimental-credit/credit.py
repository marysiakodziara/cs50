from cs50 import get_string
from cs50 import get_int

def main():

    n = get_int("the number is: ")
    digits = digits_num(n)
    print(digits)
    validation = lunhs_algorithm(n)
    print(validation)


def digits_num(x):
    k = 1
    while x > 1:
        if x > 10:
            k += 1
        x = x / 10

    return k

def lunhs_algorithm(x):
    sum = 0
    prod_digits = 0
    for i in range(x):
        every_other = (2 * ((x / 10) - ((x / 100) * 10)))
        remaining_numb = (x - ((x / 10) * 10))
        if every_other > 9:
            prod_digits = (every_other / 10) + (every_other - ((every_other / 10) * 10))
        else :
            prod_digits = every_other

        sum = sum + prod_digits + remaining_numb
        x = x / 100

    if sum % 10 == 0:
        a = 1
        return a
    else:
        a = 0
        return a


if __name__ == "__main__":
    main()