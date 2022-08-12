#include <cs50.h>
#include <stdio.h>

int digits_num(long x);
int lunhs_algorithm(long x);
void answer(long x, int k, int y);

int main(void)
{
    long n;
    n = get_long("What is the number? ");

    int digits;
    digits = digits_num(n);

    int validation;
    validation = lunhs_algorithm(n);

    answer(n, digits, validation);
}

int digits_num(long x)
{
    int k = 1;
    while (x > 1)
    {
        if (x > 10)
        {
            k++;
        }
        x = x / 10;
    }

    return k;
}

int lunhs_algorithm(long x)
{
    int sum = 0;
    for (int i = 0; x > 0; i++)
    {
        int every_other = (2 * ((x / 10) - ((x / 100) * 10)));
        int prod_digits;
        int remaining_numb = (x - ((x / 10) * 10));
        if (every_other > 9)
        {
            prod_digits = (every_other / 10) + (every_other - ((every_other / 10) * 10));
        }
        else
        {
            prod_digits = every_other;
        }

        sum = sum + prod_digits + remaining_numb;
        x = x / 100;
    }

    if (sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void answer(long x, int k, int y)
{
    int start_num;
    while (x > 99)
    {
        x = x / 10;
        start_num = x;
    }

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