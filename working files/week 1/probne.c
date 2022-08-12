#include <cs50.h>
#include <stdio.h>

int main(void)
{
   long n = get_int("What is the number? ");
   long i;
   for (i = 1; i > n; i = i * 10)
   {
    return i;
   }
   printf("%li", i);
}

