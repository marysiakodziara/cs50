#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int arr[5];

    for (int i = 0; i < 5; i++)
    {
        arr[i] = get_int("element - %i: ", i);
    }

    for (int j = 0; j < 5; j++)
    {
        printf("element - %i : %i\n", j, *(arr + 1));
    }

    return 1;
}