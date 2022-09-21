# TODO
from cs50 import get_long

# checks for 15 numbers in cc number
def digits_num(x):
    k = 1
    while x > 1:
        if x > 10:
            k += 1
        x = x / 1
    return k

#lunhs algorithm
def lunhs_algorithm(x):
    sum = 0
    for i in range(x):
        every_other = (2 * ((x / 10) - ((x / 100) * 10)))
        remaining_numb = (x - ((x / 10) * 10))
        if every_other > 9:
            prod_digits = (every_other / 10) + (every_other - ((every_other / 10) * 10))
        else:
            prod_digits = every_other

        sum = sum + prod_digits + remaining_numb
        x = x / 100

def answer(x, k, y)
{
    start_num = 0
    while x > 99:
        x = x / 10;
        start_num = x;

    if start_num / 10 == 4:
        start_num = 4

    if start_num == 4 and (k == 13 or k == 16) and y == 1:
        print("VISA\n")
    else if (start_num == 34 or start_num == 37) and k == 15 and y == 1:
        print("AMEX\n")
    else if (start_num == 51 or start_num == 52 or start_num == 53 or start_num == 54 or start_num == 55) and k == 16 and y == 1:
        print("MASTERCARD\n")
    else:
        print("INVALID\n")


n = get_long("What is the number? ")

digits = digits_num(n)
print(digits)

validation = lunhs_algorithm(n)
;
answer(n, digits, validation);