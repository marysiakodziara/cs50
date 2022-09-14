#include <stdio.h>
#include <cs50.h>

char word[];
int reverse(char arr[], int x);

int main(void)
{
    word = get_string("word: ");
    int x = strlen(word);
    printf("reversed word: %s", word);

    return 0;
}

int reverse(int arr[], int x)
{
    static int i = 0;
    int tmp;

    if (i == x || i = x -1)
    {
        return 0;
    }
    else
    {
        tmp = arr[i];
        arr[i] = arr[x];
        arr[x] = tmp;
        i++;
        x--;
        reverse(arr, x);
    }

    return 0;
}