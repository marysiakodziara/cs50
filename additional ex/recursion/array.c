#include <stdio.h>
#include <cs50.h>

int print(int elem, int arr[x]);

int main(void)
{
    int elem = get_int("number of elements: ");
    int arr[elem];
    int index = elem - 1;

    for (int i = 0; i < elem; i++)
    {
        arr[i] = 2 + (2 * i);
    }
    print(index, &arr[elem]);
}

int print(int elem, int arr[x])
{
    if (elem == 0)
    {
        printf("%i ", arr[elem]);
        return 0;
    }
    else
    {
        elem--;
        print(elem, &arr[elem]);
        printf("%i ", arr[elem - 1]);
    }

    return 1;
}