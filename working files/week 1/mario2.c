#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("What size: ");
    }
    while (n < 1);

    int x = n - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           for (int k = 0; k < n; k++)
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
        printf("!");
        printf(" ");

        if (x > j)
        {
        printf("#");
        }
        else
        {
            printf(" ");
        }

        }
    printf("%i", x);
    printf("\n");
    x--;
    }
}