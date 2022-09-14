#include <stdio.h>
#include <cs50.h>

long int factorial(long int x);

int main(void)
{
    long int x = get_long("number: ");
    x = factorial(x);
    printf("factorial is: %li\n", x);

    return 0;
}

long int factorial(long int x)
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