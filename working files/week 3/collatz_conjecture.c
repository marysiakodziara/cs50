#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
  int number = get_int("Give the number: ");
  int sum3 = collatz(number);
  printf("%i\n", sum3);
}

int collatz(int n)
{
    int how_many;
    if (n == 1)
    return 0;
    else if ((n % 2) == 0)
    return 1 + collatz(n/2);
    else
    return 1 + collatz(3 * n + 1);
}

