#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string textb);

int main(void)
{
    string text1 = get_string("Write text sample: ");
    int lett = count_letters(text1);
    printf("%i letters\n", lett);
    int word = count_words(text1);
    printf("%i words\n", word);
}

int count_letters(string text)
{
    int n = strlen(text);
    int letters = 0;
    for (int i = 0; i < n; i++ )
    {
        if(isupper(text[i]))
        {
            letters += 1;
        }
        if(islower(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

int count_words(string textb)
{
    int n = strlen(textb);
    int words = 0;
    for (int i = 0; i < n; i++ )
    {
        if (strcmp(textb[i], " ") == 0)
        {
            words += 1;
        }
    }
    return words;
}