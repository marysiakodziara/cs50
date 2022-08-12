#include <cs50.h>
#include <stdio.h>

int valid_number(long number, int wanted);
int lunhs_algorithm(long number);


int main(void)
{
    long n;
    int digits = 1;

   n = get_long("What is the number? ");
   digits = valid_number(n, digits);

   int suma = 0;
   for (int i = 0; n > 0; i++)
   {
     int every_other = (2*((n / 10) - ((n / 100) * 10)));
     int prod_digits;
     int remaining_numb = (n - ((n/10)*10));
     if( every_other > 9)
     {
        prod_digits = (every_other / 10 ) + (every_other - ((every_other / 10)*10));
     }
     else
     {
        prod_digits = every_other;
     }

     suma = suma + prod_digits + remaining_numb;
     n = n / 100;
   }
printf("%i\n", suma);
if ( suma % 10 == 0)
{
    printf("That is a credit card number\n");
}
else
{
    printf("Wrong number\n");
}


//if (digits < 13 || digits == 14 || digits > 16)
//{
//    printf("INVALID\n");
//}
//else
//{
//    printf("code in progress\n");
//}
//printf("%li \n", n);
}

int valid_number(long number, int wanted)
{
   while (number > 1)
   {
    if (number > 10)
    {
        wanted++;
    }
   number = number / 10;
   }

   return wanted;
}

int lunhs_algorithm(long number)
{
    
}