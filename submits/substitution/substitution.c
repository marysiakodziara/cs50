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
     string key = argv[1]
     for (int i = 0; i < command; i++ )
     {
        if (isupper(key[i]) != 0 && islower(key[i]) != 0)
        {
           printf("Key must contain 26 characters.\n");
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