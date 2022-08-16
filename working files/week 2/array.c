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
        printf("")
    }
}

int compute_score(string word)
{
    int i = 0;
    int suma = 0;
    while (word[i] != "\o")
    {
        if(word[i] == "a" || word[i] == "A")
        {
            suma = suma + POINTS[0];
        }
        if else (word[i] == "b" || word[i] == "B")
        {
            suma = suma + POINTS[1];
        }
        if else (word[i] == "c" || word[i] == "C")
        {
            suma = suma + POINTS[2];
        }
        if else (word[i] == "d" || word[i] == "D")
        {
            suma = suma + POINTS[3];
        }
        if else (word[i] == "e" || word[i] == "E")
        {
            suma = suma + POINTS[4];
        }
        if else (word[i] == "f" || word[i] == "F")
        {
            suma = suma + POINTS[5];
        }
        if else (word[i] == "g" || word[i] == "G")
        {
            suma = suma + POINTS[6];
        }
        if else (word[i] == "h" || word[i] == "H")
        {
            suma = suma + POINTS[7];
        }
        if else (word[i] == "i" || word[i] == "I")
        {
            suma = suma + POINTS[8];
        }
        if else (word[i] == "j" || word[i] == "J")
        {
            suma = suma + POINTS[9];
        }
        if else (word[i] == "k" || word[i] == "K)
        {
            suma = suma + POINTS[10];
        }
        if else (word[i] == "l" || word[i] == "L")
        {
            suma = suma + POINTS[11];
        }
        if else (word[i] == "m" || word[i] == "M")
        {
            suma = suma + POINTS[12];
        }
        if else (word[i] == "n" || word[i] == "N")
        {
            suma = suma + POINTS[13];
        }
        if else (word[i] == "o" || word[i] == "O")
        {
            suma = suma + POINTS[14];
        }
        if else (word[i] == "p" || word[i] == "P")
        {
            suma = suma + POINTS[15];
        }
        if else (word[i] == "q" || word[i] == "Q")
        {
            suma = suma + POINTS[16];
        }
        if else (word[i] == "r" || word[i] == "R")
        {
            suma = suma + POINTS[17];
        }
        if else (word[i] == "s" || word[i] == "S")
        {
            suma = suma + POINTS[18];
        }
        if else (word[i] == "t" || word[i] == "T")
        {
            suma = suma + POINTS[19];
        }
        if else (word[i] == "u" || word[i] == "U")
        {
            suma = suma + POINTS[20];
        }
        if else (word[i] == "v" || word[i] == "V")
        {
            suma = suma + POINTS[21];
        }
        if else (word[i] == "w" || word[i] == "W")
        {
            suma = suma + POINTS[22];
        }
        if else (word[i] == "x" || word[i] == "X")
        {
            suma = suma + POINTS[23];
        }
        if else (word[i] == "y" || word[i] == "Y")
        {
            suma = suma + POINTS[24];
        }
        if else (word[i] == "z" || word[i] == "Z")
        {
            suma = suma + POINTS[25];
        }
        else
        {
            suma = suma;
        }
    }
    return suma;

}