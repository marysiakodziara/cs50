#include <cs50.h>
#include <stdio.h>

int collatz(int n);
int sum(int n);

int main(void)
{
  int k2 = 0;
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

int sum(int n);
{
  int sum2 = 1;
  while (n != 1)
  {
    int one = collatz(number);
    sum2 += 1;
  }
}

