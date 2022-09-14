#include <stdio.h>
#include <cs50.h>

string word;
int reverse(string w, int x);

int main(void)
{
    word = get_string("word: ");
    int x = strlen(word);
    printf("reversed word: %s", word);

    return 0;
}

int reverse(string w, int x)
{
    static int i = 0;
    char tmp;

    if (i == x || i = x -1)
    {
        return 0;
    }
    else
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