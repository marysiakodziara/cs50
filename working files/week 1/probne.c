#include <cs50.h>
#include <stdio.h>

int main(void)
{
   long n = get_long("What is the number? ");
   int digits = 1;

   while (n > 1)
   {
    if (n > 10)
    {
        n = n / 10;
        digits++;
    }
    else
    {
        return digits;
    }
   }

   printf("%i\n", digits);
}

