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
    if (elem > 0)
    {
        printf("%i ", arr[i]);
        elem--;
        print(elem, &arr[i + 1]);
    }
    else
    {
        return 0;
    }

    return 1;
}