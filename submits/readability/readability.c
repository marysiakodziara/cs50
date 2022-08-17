#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text1 = get_string("Write text sample: ");
    int lett = count_letters(text1);
    printf("%i letters\n", lett);
    int word = count_words(text1);
    printf("%i words\n", word);
    int sen = count_sentences(text1);
    printf("%i sentences\n", sen);
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

int count_words(string text)
{
    int n = strlen(text);
    int words = 1;
    for (int i = 0; i < n; i++)
    {
        if (text[i] == ' ')
        {
            words += 1;
        }
    }

    return words;
}

int count_sentences(string text)
{
    int n = strlen(text);
    int sentence = 0;
    for (int i = 0; i < n; i++)
    {
        if (text[i] == '.')
        {
            sentence += 1;
        }
        else if (text[i] == '!')
        {
            sentence += 1;
        }
        else if (text[i] == '?')
        {
            sentence += 1;
        }
    }

    return sentence;
}