#include <cs50.h>
#include <stdio.h>

int main(void)
{
   long n = get_int("What is the number? ");
   int ten = 10;
   int digits = 0;
   while (n > 1)
   {
    n = n / ten;
    ten = ten * 10;
    digits++;
    return digits;
   }

   printf("%i", digits);
}

