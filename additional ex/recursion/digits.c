#include <stdio.h>
#include <cs50.h>

int digit(int x, int i);

int main(void)
{
    int i = 0;
    int x = get_int("number: ");
    i = digit(x, i);
    printf("%i\n", i);

}

int digit(int x, int i)
{
    if (x < 1)
    {
        return 0;
    }
    else
    {
        i++;
        x = x/10;
        printf("%i ", x);
        digit(x, i);
    }

    return i;
}