#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int key_validation(string arg_v[], int arg_c);
string cipher(string text, string arg_v[]);

int main(int argc, string argv[])
{

    int open = key_validation(argv, argc);
    if (open == 0) // po tym przechodzę do szyfru
    {
        string origin = get_string("plaintext: ");
        // tutaj wrzucam to do funkcji szyfrującej
        string ciphered = cipher(origin, argv);
        printf("ciphertext: %s\n", ciphered);
        return 0;
    }
    else          // po tym wyrzucam z programu
    {
        printf("invalid key\n");
        return 1;
    }

}

int key_validation(string arg_v[], int arg_c)
{
    int answer;
    int command = strlen(arg_v[arg_c - 1]);
    if (arg_c == 2  && command == 26) // sprawdza czy klucz jest i czy jest wyst długi
    {
        int score = 0;
        string key = arg_v[1];
        for (int i = 0; i < command; i++) //sprawdzam czy wszystkie znaki są alfabetyczne
        {
            if (isalpha(key[i]))
            {
                score += 1;
            }
        }
        if (score == 26)
                {
                    int tab[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int k = 0; k < 26; k++)
                    {
                        if (isupper(key[k])) // sprawdza czy litery się nie powtarzają
                        {
                            tab[key[k] - 'A'] += 1;
                        }
                        else if (islower(key[k]))
                        {
                            tab[key[k] - 'a'] += 1;
                        }
                    }
                    int tab2 = 1;
                    for (int z = 0; z < 26; z++)
                    {
                        tab2 = tab2 * tab[z];
                    }
                    if (tab2 == 1)
                    {
                        answer = 0;
                    }
                }
        }
    else
    {
        answer = 1;
    }

    if (answer == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string cipher(string text, string arg_v[])
{
   string key = arg_v[1];
   int len = strlen(arg_v[1]);
   for (int i = 0; i < len; i++)
   {
      if (isupper(text[i]))
      {
         text[i] = toupper(key[text[i] - 'A']);
      }
      else if (islower(text[i]))
      {
         text[i] = tolower(key[text[i] - 'a']);
      }
      else
      {
         text[i] = text[i];
      }
   }
   return text;
}