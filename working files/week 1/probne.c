#include <cs50.h>
#include <stdio.h>

int main(void)
{
   long n = get_long("What is the number? ");
   int ten = 10;
   int digits = 0;
   do
   {
    n = n / ten;
    digits++;
   }
   while (n > 1);

   printf("%i\n", digits);
}

