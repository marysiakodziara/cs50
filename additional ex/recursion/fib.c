#include <stdio.h>
#include <cs50.h>

int fib(int x,int y);
int ser;

int main(void)
{
    ser = get_int("number of series: ");
    int x = 0, y = 1;
    fib(x, y);
}

int fib(int x, int y)
{
    static int i = 1;
    int next;

    if (i == ser)
    {
        return 0;
    }
    else
    {
        next = x + y;
        x = y;
        y = next;
        printf("%i ", next);

        i++;
        fib(x, y);
    }
    return 0;

}