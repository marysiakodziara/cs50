#include <stdio.h>
#include <cs50.h>

int digit(float x, int i);

int main(void)
{
    int i = 0;
    float x = get_int("number: ");
    i = digit(x, i);
    printf("%i\n", i);

}

int digit(float x, int i)
{
    if (x < 1)
    {
        return i;
    }
    else
    {
        i++;
        x = x/10;
        printf("%f, %i\n ", x, i);
        digit(x, i);
    }

    printf("\n");
    return i;
}