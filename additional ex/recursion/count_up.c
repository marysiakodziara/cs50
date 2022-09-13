#include <stdio.h>
#include <cs50.h>

int count(int x);
void count_nd(int x);

int main(void)
{
    int x = 1;
    count(x);
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

void count_nd(int x)
{
    int k;
    if (x > 1)
    {
        k = 
        count_nd(x - 1)
    }
    else
    {
        printf()
    }
}