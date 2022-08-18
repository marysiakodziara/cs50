#include <cs50.h>
#include <stdio.h>

int collatz(int n);
int sum(int n);

int main(void)
{
  int number = get_int("Give the number: ");
  int sum3 = sum(number);
  printf("%i\n", sum3);
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

int sum(int n)
{
  int sum2 = 1;
  int to_one = n;
  while (to_one != 1)
  {
    to_one = collatz(n);
  }
      sum2 += 1;
return sum2;
}

