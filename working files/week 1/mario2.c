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

    for (int i = 0; i < n; i++)
    {
        int k = n - 1;

        for (int j = 0; j < n; j++)
        {
           if (k > j)
           {
            printf(" ");
           }
           else
           {
            printf("#");
           }
           printf(k);
        }

        printf("\n");
        k--;
    }
}