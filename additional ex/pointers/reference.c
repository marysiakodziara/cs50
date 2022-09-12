#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("first number:");
    int y = get_int("second number:");

    printf("The sum of %i and %i is %i\n", x, y, x + y);

    return 1;
}