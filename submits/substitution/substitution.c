#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int key_validation(string arg_v[], int arg_c);

int main(int argc, string argv[])
{

   int open = key_validation(argv, argc);
   if (open == 0)
   {
    printf("valid key\n");
    return 0;
   }
   else
   {
    printf("invalid key\n");
    return 1;
   }

}

int key_validation(string arg_v[], int arg_c)
{
   int command = strlen(arg_v[arg_c - 1]);
   if (arg_c == 2  && command == 26)
   {
     int score = 0;
     string key = arg_v[1];
     for (int i = 0; i < command; i++ ) //sprawdzam czy wszystkie znaki są alfabetyczne
     {
        if (isupper(key[i]) == 0 && islower(key[i]) == 0)
        {
           score += 1;
           if (score == 0)
           {
              int tab[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
              for (int k = 0; k < 26; k++)
              {
                  if (isupper(key[k]))
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
                    return 0;
              }
           }
        }
     }
   }
else
{
    return 1;
}
}
