#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
   argc == 2  && strlen(argv[1]) == 26 // tylko wtedy program puszcza dalej
   argc == 1 // program wyświetla Usage: ./substitution key
   argc == 2 && strlen(argv[1]) != 26 // program wyświetla Key must contain 26 characters.
   
}