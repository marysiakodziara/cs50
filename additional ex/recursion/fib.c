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
        x--;
        k += fib(x);
        printf("%i ", k);
    }
    else if (x == 1)
    {
        printf("%i ", k);
        return 0;
    }
    else
    {
        return 0;
    }

    return 1;

}