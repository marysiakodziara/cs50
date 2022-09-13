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
    print(index, &arr[elem]);
}

int print(int elem, int arr[elem])
{
    static int i = elem - 1;
    if (i == 0)
    {
        printf("%i ", arr[i]);
        i
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