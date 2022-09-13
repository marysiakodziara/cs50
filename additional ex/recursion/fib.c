#include <stdio.h>
#include <cs50.h>

int sum(int x);
int sumof = 0;
int k = 1;

int main(void)
{
    int x = get_int("number of series: ");
    fib(x);
}

int fib(int x)
{
    while (k < x)
    {
    if (k < x)
    {
        k++;
        sumof += fib(k)
    }
    else
    {
        return sumof;
    }
    }

    return 0;

}