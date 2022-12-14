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

    if (i == x)
    {
        return 0;
    }
    else if (i < x)
    {
        tmp = w[i];
        w[i] = w[x];
        w[x] = tmp;
        i++;
        x--;
        reverse(w, x);
    }

    return 0;
}