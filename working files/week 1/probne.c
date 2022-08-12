#include <cs50.h>
#include <stdio.h>

int 

int main(void)
{
   long n = get_long("What is the number? ");
   int digits = 1;

   while (n > 1)
   {
    if (n > 10)
    {
        digits++;
    }
   n = n / 10;
   }

if (digits < 13 || digits == 14 || digits > 16)
{
    printf("INVALID\n");
}
else
{
    printf("code in progress\n");
}
}

