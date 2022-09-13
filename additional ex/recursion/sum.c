#include <stdio.h>
#include <cs50.h>

int sum(int x);
int sumof = 0;

int main(void)
{
    int x = get_int("input number: ");
    sum(x);
    printf("sum is: %i\n", sumof);

    return 1;
}

int sum(int x)
{
    if (x > 0)
    {
        sumof += x;
        x--;
        sum(x);
    }
    else
    {
        return x;
    }

    return 0;
}
