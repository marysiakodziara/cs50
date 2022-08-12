#include <cs50.h>
#include <stdio.h>

int valid_number(long number, int wanted);


int main(void)
{
    long n;
    int digits = 1;

   n = get_long("What is the number? ");
   digits = valid_number(n, digits);

   int suma = 0;
   for (int i = 0; n > 1; i++)
   {
     int every_other = (2*((n / 10) - ((n / 100) * 10)));
     int remaining_numb = (n - ((n / 10) * 10));
     suma = suma + every_other + remaining_numb;
     n = n / 100;

     printf("%i and %i\n", every_other, remaining_numb);
   }
printf("%i\n", suma);

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

