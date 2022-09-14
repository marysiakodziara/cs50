#include <stdio.h>
#include <cs50.h>

int factorial(int x);

int main(void)
{
    int x = get_int("number: ");
    x = factorial(x);
    printf("factorial is: %i\n", x);

    return 0;
}

int factorial(int x)
{
    if (x == 1)
    {
        return x;
    }
    else
    {
        x = x * factorial(x - 1);
    }

    return x;
}