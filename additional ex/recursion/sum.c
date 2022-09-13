#include <stdio.h>
#include <cs50.h>

int sum(int x);

int main(void)
{
    int x;
    do
    {
        x = get_int("input number: ");
    }
    while (x <= 5 && x >= 1);
    sum(x);
}

int sum(int x)
{
    if (x > 1)
    {
        x = x + sum(x - 1);
        printf("sum is: %i\n", x);
    }
    else
    {
        return x;
    }

    return 0;
}
