#include <stdio.h>
#include <cs50.h>

int bigger = 0;
int biggest(int arr[], int x);

int main(void)
{
    int x = get_int("elements: ");
    int arr[x];
    for (int i = 0; i < x; i++)
    {
        arr[i] = get_int("element %i: ", i);
        printf("\n");
    }
    biggest(arr, x);
    printf("the biggest number in array is: %i\n", bigger);

    return 0;
}

int biggest(int arr[], int x)
{
    static int i = 0;
    if (i == 0)
    {
        bigger = arr[i];
        i++;
        return 0;
    }
    else if (i < x - 1)
    {
        if (bigger > arr[i])
        {
            i++;
            biggest(arr, x);
        }
        else
        {
            bigger = arr[i];
            i++;
            biggest(arr, x);
        }
    }

    return 0;
}