#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{

   if (argc == 2  && strlen(argv[1]) == 26)
   {

   } // tylko wtedy program puszcza dalej
   else if (argc == 1)
   {
     printf("Usage: ./substitution key\n");
   }
   // program wyświetla Usage: ./substitution key
   else if (argc == 2 && strlen(argv[1]) != 26)
   {
     printf("Key must contain 26 characters.\n");
   } // program wyświetla Key must contain 26 characters.

}