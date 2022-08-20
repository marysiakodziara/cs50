#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}

void draw(int n)
{
    if (n == 1)
    printf("*");
    else
    {
        return draw(n-1);
        for (int i = 1; i <= n; i++)
        {
            printf("*");
        }

    }

}