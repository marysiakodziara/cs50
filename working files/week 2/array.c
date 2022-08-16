#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if(score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if( score1 == score2)
    {
        printf("Tie!");
    }
    else
    {
        printf("Player 2 wins!");
    }
}

int compute_score(string word)
{
    int i = 0;
    int suma = 0;
    int lenght = strlen(word);
    while ( i != lenght )
    {
        if(word[i] == "a" || word[i] == "A")
        {
            suma = suma + POINTS[0];
        }
        else if (word[i] == "b" || word[i] == "B")
        {
            suma = suma + POINTS[1];
        }
        else if (word[i] == "c" || word[i] == "C")
        {
            suma = suma + POINTS[2];
        }
        else if (word[i] == "d" || word[i] == "D")
        {
            suma = suma + POINTS[3];
        }
        else if (word[i] == "e" || word[i] == "E")
        {
            suma = suma + POINTS[4];
        }
        else if (word[i] == "f" || word[i] == "F")
        {
            suma = suma + POINTS[5];
        }
        else if (word[i] == "g" || word[i] == "G")
        {
            suma = suma + POINTS[6];
        }
        else if (word[i] == "h" || word[i] == "H")
        {
            suma = suma + POINTS[7];
        }
        else if (word[i] == "i" || word[i] == "I")
        {
            suma = suma + POINTS[8];
        }
        else if (word[i] == "j" || word[i] == "J")
        {
            suma = suma + POINTS[9];
        }
        else if (word[i] == "k" || word[i] == "K)
        {
            suma = suma + POINTS[10];
        }
        else if (word[i] == "l" || word[i] == "L")
        {
            suma = suma + POINTS[11];
        }
        else if (word[i] == "m" || word[i] == "M")
        {
            suma = suma + POINTS[12];
        }
        else if (word[i] == "n" || word[i] == "N")
        {
            suma = suma + POINTS[13];
        }
        else if (word[i] == "o" || word[i] == "O")
        {
            suma = suma + POINTS[14];
        }
        else if (word[i] == "p" || word[i] == "P")
        {
            suma = suma + POINTS[15];
        }
        else if (word[i] == "q" || word[i] == "Q")
        {
            suma = suma + POINTS[16];
        }
        else if (word[i] == "r" || word[i] == "R")
        {
            suma = suma + POINTS[17];
        }
        else if (word[i] == "s" || word[i] == "S")
        {
            suma = suma + POINTS[18];
        }
        else if (word[i] == "t" || word[i] == "T")
        {
            suma = suma + POINTS[19];
        }
        else if (word[i] == "u" || word[i] == "U")
        {
            suma = suma + POINTS[20];
        }
        else if (word[i] == "v" || word[i] == "V")
        {
            suma = suma + POINTS[21];
        }
        else if (word[i] == "w" || word[i] == "W")
        {
            suma = suma + POINTS[22];
        }
        else if (word[i] == "x" || word[i] == "X")
        {
            suma = suma + POINTS[23];
        }
        else if (word[i] == "y" || word[i] == "Y")
        {
            suma = suma + POINTS[24];
        }
        else if (word[i] == "z" || word[i] == "Z")
        {
            suma = suma + POINTS[25];
        }
        else
        {
            suma = suma;
        }
        i++;
    }
    return suma;

}