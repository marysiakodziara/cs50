#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
        printf("ciphertext:%s\n", ciphered);
    }
    else          // po tym wyrzucam z programu
    {
        printf("invalid key\n");
    }
return open;
}

int key_validation(string arg_v[], int arg_c)
{
    int answer;
    int command = strlen(arg_v[arg_c - 1]);
    int score = 0;
    string key = arg_v[arg_c - 1];
    if (command == 26)
    {
        for (int i = 0; i < command; i++) //sprawdzam czy wszystkie znaki są alfabetyczne
        {
            if (isalpha(key[i]))
            {
                score += 1;
            }
        }
    }
    // powyżej deklaracja zmiennych (długość szyfru, output funkcji) i czy znaki są alfabetyczne

    int same = 0;

        for(int k = 0; k < command; k++)
        {
           for(int z = 0; z < k; z++)
           {
                if(key[k] == key[z] && k != z)
                {
                      same += 1;
                }
           }
        }
    // powyżej sprawdza czy znaki się nie powtarzają
    if (arg_c == 2  && command == 26 && score == 26 && same == 0) // sprawdza czy klucz jest i czy jest wyst długi
    {
       answer = 0;
    }
    else
    {
       answer = 1;
    }

    return answer;
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