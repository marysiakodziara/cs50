#include <cs50.h>
#include <stdio.h>

int valid_number(long x);
string lunhs_algorithm(long x);


int main(void)
{
    long n;
    int digits;
    string validation;

   n = get_long("What is the number? ");
   digits = valid_number(n);
   // zmieniłam zapis funkcji powyżej i sprawdzam czy nadal działa, na razie nie jest mi potrzebna
   printf("%i\n", digits);
   validation = lunhs_algorithm(n);




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

int valid_number(long x)
{
   int k;
   while (x > 1)
   {
    if (x > 10)
    {
        k++;
    }
   x = x / 10;
   }

   return k;
}

string lunhs_algorithm(long x)
{
   int suma = 0;
   for (int i = 0; x > 0; i++)
   {
     int every_other = (2*((x / 10) - ((x / 100) * 10)));
     int prod_digits;
     int remaining_numb = (x - ((x/10)*10));
     if( every_other > 9)
     {
        prod_digits = (every_other / 10 ) + (every_other - ((every_other / 10)*10));
     }
     else
     {
        prod_digits = every_other;
     }

     suma = suma + prod_digits + remaining_numb;
     x = x / 100;
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
}