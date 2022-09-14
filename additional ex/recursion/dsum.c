#include <stdio.h>
#include <cs50.h>

int sum = 0;
int dsum(int x);

int main(void)
{
    int x = get_int("number: ");
    dsum(x);
    printf("sum: %i\n", sum);

    return 0;
}

int dsum(int x)
{
    if (x < 10)
    {
        sum = x;
        return 0;
    }
    else
    {
        sum += x % 10;
        x = x / 10;
        dsum(x);
    }

    return 0;
}