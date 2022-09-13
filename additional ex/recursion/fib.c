#include <stdio.h>
#include <cs50.h>

int fib(int x);
int x;

int main(void)
{
    int k = 1;
    x = get_int("number of series: ");
    fib(k);
}

int fib(int k)
{
    if (x > 1)
    {
        x--;
        k = fib(x - 1) + fib (x - 2);
        printf("%i ", k);
    }
    else
    {
        return 1;
    }

    return 0;
}