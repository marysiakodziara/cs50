#include <stdio.h>
#include <cs50.h>

int fib(int x);
int sum;

int main(void)
{
    int x = get_int("number of series: ");
    fib(x);
}

int fib(int x)
{
    int k = 1;
    if (x > 1)
    {
        sum += fib(x - 1);
        printf("%i ", sum);
    }
    else if (x == 1)
    {
        sum = k;
        printf("%i ", k);
        return sum;
    }
    else
    {
        return 0;
    }

    return 1;

}