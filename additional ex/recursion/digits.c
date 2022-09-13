#include <stdio.h>
#include <cs50.h>

int digit(int x, int i);

int main(void)
{
    int i = 0;
    int x = get_int("number: ");
    printf("%i\n", digit(x, i));

}

int digit(int x, int i)
{
    if (x < 1 && x > 0)
    {
        return i;
    }
    else
    {
        x = x/10;
        i++;
        digit(x, i);
    }

    return i;
}