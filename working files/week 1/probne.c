#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Size of the pyramid: ");
    }
    while (n < 1 && n > 8);

    for (int i = 0; i < n; i++) //wysokość, enter
    {
         
    }
}