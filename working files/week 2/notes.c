 && score == 26 && same == 0




else if (argc == 1)
   {
     printf("Usage: ./substitution key\n");
   }
   // program wyświetla Usage: ./substitution key
   else if (argc == 2 && command != 26)
   {
     printf("Key must contain 26 characters.\n");
   } // program wyświetla Key must contain 26 characters.



// w ostatecznym pliku to jest wersja sprzed zmiany
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
     int tab2 = 1;
     for (int i = 0; i < 26; i++)
     {
         tab2 = tab2 * tab[i];
     }
     if (tab2 == 1)
     {
        printf("Key passed for a second time\n");
     }
     else
     {
       printf("Key must contain 26 letters.\n");
     }
   } // tylko wtedy program puszcza dalej



   // kod z dnia 18.08 bez zmian
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




// nowy kod na sprawdzenie czy litery się nie powtarzają, bez zmian w zagnieżdżeniu ifów
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
        int same = 0;
        if (score == 26)
        {
            for(int k = 0; k < command; k++)
            {
                for(int z = 0; z < command; z++)
                {
                   if(key[k] == key[z] && k != z)
                   {
                      same += 1;
                   }
                }
            }
        }


}
}