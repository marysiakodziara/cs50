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
    int letters = count_letters(text1);
    int words = count_words(text1);
    int sentences = count_sentences(text1);
    float L = (letters / words * 100);
    float S = (sentences / words * 100);
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    printf("%f, %i\n", L, count_letters(text1));
    printf("%f\n", S);
    printf("%f\n", index);
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
        printf("Grade %f\n", index);
    }
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