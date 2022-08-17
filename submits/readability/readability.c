#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);

int main(void)
{
    string text1 = get_string("Write text sample: ");
    int score = count_letters(text1);
    printf("%i\n", score);
}

int count_letters(string text)
{
    int n = strlen(text);
    int letters = 0;
    for (int i = 0; i < n; i++ )
    {
        if(isupper(word[i]))
        {
            letters += 1;
        }
        if(islower(word[i]))
        {
            letters += 1;
        }
        return letters;
    }
}