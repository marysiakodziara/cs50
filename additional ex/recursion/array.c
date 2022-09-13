#include <stdio.h>
#include <cs50.h>

int print(int elem, int arr[]);

int main(void)
{
    int elem = get_int("number of elements: ");
    int arr[elem];

    for (int i = 0; i < elem; i++)
    {
        arr[i] = 2 + (2 * i);
        printf("%i ", arr[i]);
    }

    printf("\n");
    print(elem, arr);
}

int print(int elem, int arr[])
{
    static int i = 0;
    if (i < elem)
    {
        printf("%i ", arr[i]);
        print(elem, &arr[i]);
    }

    return 1;
}