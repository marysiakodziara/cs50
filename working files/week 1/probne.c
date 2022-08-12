#include <cs50.h>
#include <stdio.h>

int valid_number(long n, int digits);

long n;
int digits = 1;

int main(void)
{
   n = get_long("What is the number? ");
   digits = valid_number(n, digits);

if (digits < 13 || digits == 14 || digits > 16)
{
    printf("INVALID\n");
}
else
{
    printf("code in progress\n");
}
}

int valid_digits(long n, int digits)
{
   long n;
   while (n > 1)
   {
    if (n > 10)
    {
        digits++;
    }
   n = n / 10;
   }

   return digits;
}