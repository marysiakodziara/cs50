#include <stdio.h>
#include <cs50.h>

int count(int x);

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
        return;
    }
}