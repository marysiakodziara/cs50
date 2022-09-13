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
        k = fib(k - 1) + fib (k - 2);
        printf("%i ", k);
    }
    else
    {
        printf("%i ", k);
        return k;
    }

    return 0;
}