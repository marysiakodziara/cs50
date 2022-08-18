#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
  int number = get_int("Give the number: ");
  int one = collatz(number);
  printf("%i\n", one);
}

int collatz(int n)
{
    if (n == 1)
    return 1;
    else if ((n % 2) == 0)
    return collatz(n/2);
    else
    return collatz(3 * n + 1);
}

