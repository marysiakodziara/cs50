#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{
   int command = strlen(argv[argc - 1]);
   if (argc == 2  && command == 26)
   {
     int score = 0;
     string key = argv[1];
     for (int i = 0; i < command; i++ ) //sprawdzam czy wszystkie znaki są alfabetyczne
     {
        if (isupper(key[i]) == 0 && islower(key[i]) == 0)
        {
           score += 1;
        }
     }
     if (score == 0)
     {
        printf("Key passed\n");
     }
     else
     {
       printf("Key must contain 26 letters.\n");
     }

     int tab[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
     for (int i = 0; i < 26; i++)
     {
        if (isupper(key[i]))
        {
            tab[key[i] - 'A'] += 1;
        }
        else if (islower(key[i]))
        {
            tab[key[i] - 'a'] += 1;
        }
     }
   } // tylko wtedy program puszcza dalej


   else if (argc == 1)
   {
     printf("Usage: ./substitution key\n");
   }
   // program wyświetla Usage: ./substitution key
   else if (argc == 2 && command != 26)
   {
     printf("Key must contain 26 characters.\n");
   } // program wyświetla Key must contain 26 characters.

}