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
    if (x > 2)
    {
        x--;
        k = fib(k - 1) + fib (k - 2);
        printf("%i ", k);
    }
    if (x == 2)
    {
        x--;
        k = fib(k);
        printf("%i ", k);
    }
    else
    {
        return k;
    }

    return 0;
}