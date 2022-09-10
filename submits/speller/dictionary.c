// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //fopen to dictionary
    FILE *file = fopen(dictionary, "r");

    //checks for null
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }

    char word[LENGHT + 1];
    while(fscanf(file, "%s", word) != EOF) //run till reaching end of the file
    {
        //dma for new ndoe
        node n* = malloc(sizeof(node));
        //checks for null
        if (n == NULL)
        {
            return 1;
        }
        //call the hash function on the given string
        int index = hash(word[0]);
        //copy string into node using strcpy
        n->word = strcpy(n->word, word);
        //insert new node into hash table
        n->next = table[index];
        table[index] = n;
    }

    fclose(file);
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
