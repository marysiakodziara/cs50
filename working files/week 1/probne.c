#include <cs50.h>
#include <stdio.h>

int valid_number(long x);
int lunhs_algorithm(long x);
int


int main(void)
{
    long n;
    int digits;
    int validation;

   n = get_long("What is the number? "); //input użytkownika
   digits = valid_number(n); //liczba cyfr
   // zmieniłam zapis funkcji powyżej i sprawdzam czy nadal działa, na razie nie jest mi potrzebna
   printf("%i\n", digits);
   validation = lunhs_algorithm(n);
   printf("%i\n", validation);


}

int valid_number(long x)
{
   int k = 1;
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

int lunhs_algorithm(long x)
{
   int sum = 0;
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

     sum = sum + prod_digits + remaining_numb;
     x = x / 100;
   }

   if ( sum % 10 == 0)
   {
    return 1;
   }
   else
   {
    return 0;
   }

}