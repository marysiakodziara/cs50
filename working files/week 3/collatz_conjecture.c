#include <cs50.h>
#include <stdio.h>

int collatz(int n);
int sum(int n, int sum2);

int main(void)
{
  int score = 0;
  int number = get_int("Give the number: ");
  int sum3 = sum(number, score);
  printf("%i\n", sum3);
}

int collatz(int n)
{
    int how_many;
    if (n == 1)
    return 0;
    else if ((n % 2) == 0)
    return collatz(n/2);
    else
    return collatz(3 * n + 1);
}

