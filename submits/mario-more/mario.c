#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height of the pyramid: ");
    }
    while (n < 1 || n > 8);

    int x = n - 1;
    int z = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (x > j)
            {
                 printf(" ");
            }
            else
            {
                 printf("#");
            }
        }

        printf("  ");

        for (int k = 0; k < n; k++)
        {
            if (z > k)
            {
                 printf("#");
            }
         }

    printf("\n");
    x--;
    z++;
    }
}