#include <stdio.h>
#include <cs50.h>

int digit(float x);
int i = 0;

int main(void)
{
    float x = get_int("number: ");
    digit(x);
    printf("\n%i\n", i);
}

int digit(float x)
{
    if (x < 1)
    {
        return i;
    }
    else
    {
        i++;
        x = x/10;
        digit(x);
    }

    return 0;
}