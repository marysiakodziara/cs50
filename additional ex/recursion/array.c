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
    print(elem, &arr[elem]);
}

int print(int elem, int arr[elem])
{
    static int i = 0;
    if (i < elem - 1)
    {
        printf("%i ", arr[i]);
        i++;
        print(elem, &arr[i]);
    }

    return 1;
}