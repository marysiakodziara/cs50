#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text1 = get_string("Write text sample: ");
    float letters = count_letters(text1);
    float words = count_words(text1);
    float sentences = count_sentences(text1);
    float L = letters * 100 / words;
    float S = sentences / words * 100;
    float index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}

int count_letters(string text)
{
    int n = strlen(text);
    int letters = 0;
    for (int i = 0; i < n; i++)
    {
        if (isupper(text[i]))
        {
            letters += 1;
        }
        if (islower(text[i]))
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