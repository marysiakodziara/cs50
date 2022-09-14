#include <stdio.h>
#include <cs50.h>
#include <string.h>

string word;
int reverse(string w, int x);

int main(void)
{
    word = get_string("word: ");
    int x = strlen(word) - 1;
    reverse(word, x);
    printf("reversed word: %s\n", word);

    return 0;
}

int reverse(string w, int x)
{
    static int i = 0;
    char tmp;

    if (i == x || i + 1 == x)
    {
        printf("x: %i, i: %i\n", x, i);
        return 0;
    }
    else if (i + 1 == x)
    {
        i++;
        return 0;
    }
    else
    {
        tmp = w[i];
        w[i] = w[x];
        w[x] = tmp;
        i++;
        x--;
        printf("x: %i, i: %i\n", x, i);
        reverse(w, x);
    }

    return 0;
}