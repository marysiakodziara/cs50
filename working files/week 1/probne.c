#include <cs50.h>
#include <stdio.h>

int valid_number(long x);

long n;
int digits = 1;

int main(void)
{
   n = get_long("What is the number? ");
   digits = valid_number(n);

if (digits < 13 || digits == 14 || digits > 16)
{
    printf("INVALID\n");
}
else
{
    printf("code in progress\n");
}
}

valid_digits(long x)
{
   long x;
   while (x > 1)
   {
    if (x > 10)
    {
        digits++;
    }
   x = x / 10;
   }

   return digits;
}