#include <stdio.h>
#include <cs50.h>

int fib(int x);
int k = 1;

int main(void)
{
    int x = get_int("number of series: ");
    fib(x);
}

int fib(int x)
{
    if (x > 1)
    {
        k = fib(x - 1) + fib(x - 2);
        printf("%i ", k);
    }
    else
    {
        return k;
    }

    return 1;

}