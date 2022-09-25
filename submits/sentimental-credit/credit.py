from cs50 import get_string
from cs50 import get_int

def main():

    n = get_int("the number is: ")
    digits = digits_num(n)
    print(digits)
    try:
        validation = lunhs_algorithm(n)
        print(validation)
    except:
        print("dupa")



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
    while x > 0:
        every_other = (2 * ((x / 10) - ((x / 100) * 10)))
        remaining_numb = (x - ((x / 10) * 10))
        if every_other > 9:
            prod_digits = (every_other / 10) + (every_other - ((every_other / 10) * 10))
        else :
            prod_digits = every_other

        sum = sum + prod_digits + remaining_numb
        x = int(x / 100)

    if sum % 10 == 0:
        a = 1
        return a
    else:
        a = 0
        return a


def answer(x, k, y)
{
    start_num = 0
    while x > 99:
        x = x / 10
        start_num = x

    if (start_num / 10 == 4)
    {
        start_num = 4;
    }

    if (start_num == 4 && (k == 13 || k == 16) && y == 1)
    {
        printf("VISA\n");
    }
    else if ((start_num == 34 || start_num == 37) && k == 15 && y == 1)
    {
        printf("AMEX\n");
    }
    else if ((start_num == 51 || start_num == 52 || start_num == 53 || start_num == 54 || start_num == 55) && k == 16 && y == 1)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}


if __name__ == "__main__":
    main()