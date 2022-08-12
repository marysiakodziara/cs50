#include <cs50.h>
#include <stdio.h>

int main(void)
{
   long n = get_li("What is the number? ");
   for (long i = 1; i > n; i = i * 10)
   {
    return i;
   }
   printf("%li", i);
}

