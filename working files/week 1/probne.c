#include <cs50.h>
#include <stdio.h>

int main(void)
{
   long n = get_long("What is the number? ");
   int ten = 10;
   int digits = 1;
   do
   {
    n = n / ten;
    if (n > 1)
    {
        digits++;
    }
   }
   while (n > 1);

   printf("%i\n", digits);
}

