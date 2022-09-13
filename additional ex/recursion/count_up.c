#include <stdio.h>
#include <cs50.h>

int count(int x);
int count_nd(int x);

int main(void)
{
    int x = 1;
    int k = 50;
    count(x);
    printf("\n");
    count_nd(k);
}

int count(int x)
{
    if (x <= 50)
    {
        printf("%i ", x);
        x++;
        count(x);
    }
    else
    {
        return 0;
    }

    return 0;
}

int count_nd(int x)
{
    if (x >= 1)
    {
        count_nd(x-1);
        printf("%i ", x);
    }
    else
    {
        return x;
    }

    return 0;
}