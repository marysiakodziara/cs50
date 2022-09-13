#include <stdio.h>
#include <cs50.h>

int print(int elem, int arr[elem]);

int main(void)
{
    int elem = get_int("number of elements: ");
    int arr[elem];

    for (int i = 0; i < elem; i++)
    {
        arr[i] = 2 + (2 * i);
    }
    print(elem, arr);
}

int print(int elem, int arr[elem])
{
    if (elem == o)
    {
        return 0;
    }
    else
    {
        elem--;
        print(x);
        printf("%i ", arr[elem - 1]);
    }

    return 1;
}