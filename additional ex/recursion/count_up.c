#include <stdio.h>
#include <cs50.h>

int count(int x);

int main(void)
{
    int x = get_int("number : ");
    count(x);
}

int count(int x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        printf("%i, ", count(x - 1));
    }
    return 0;
}