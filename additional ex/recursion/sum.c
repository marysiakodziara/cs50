#include <stdio.h>
#include <cs50.h>

int sum(int x);
int sumof = 0;

int main(void)
{
    int x = get_int("input number: ");
    sum(x);
}

int sum(int x)
{
    if (x >= 1)
    {
        x--;
        sum(x);
        sumof += x;
        printf("sum is: %i\n", sumof);
    }
    else
    {
        x++;
        return x;
    }

    return 0;
}
