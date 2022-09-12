#include <stdio.h>
#include <cs50.h>

void count(int x);

int main(void)
{
    int x = get_int("number : ");
    count(x);
}

void count(int x)
{
    if (x == 0)
    {
        return;
    }
    else
    {
        printf("%i, ", count(x - 1));
    }
}