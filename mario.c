#include <cs50.h>
#include <stdio.h>

int main(void)
{
    do
    {
        int n = get_int("What size: ");
    }
    while (n < 1)

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}