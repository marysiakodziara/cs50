#include <stdio.h>
#include <cs50.h>

int bigger(int *st, int *nd);

int main(void)
{
    int x = get_int("first number:");
    int y = get_int("second number:");

    int *st = &x;
    int *nd = &y;

    printf("%i is the maximum number.\n", bigger(st, nd));

}

int bigger(int *st, int *nd)
{
    if(*st > *nd)
    {
        return *st;
    }
    else
    {
        return *nd;
    }

    return 1;
}


