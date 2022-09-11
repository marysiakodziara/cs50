// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"
int count_words;
int hash_code;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1300;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_code = hash(word);
    //go to node in hash table and compare word to nodes from list until true or pointer set to NULL
    node *new_node = table[hash_code];
    while (new_node != 0)
    {
        if (strcasecmp(new_node->word, word) != 0)
        {
            new_node = new_node->next;
        }
        else
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int count = 0;
    for (int i = 0; i < (LENGTH); i++)
    {
        if (strcmp(&word[i], "\0") != 0)
        {
            if (strcmp(&word[i], "'") != 0 && strcmp(&word[i], "-") != 0)
            {
                if (islower(word[i]))
                {
                    count += (word[i] - 'a' + 1);
                }
                else
                {
                    count += (word[i] - 'A' + 1);
                }
            }
            else
            {
                count += word[i];
            }
        }
        else
        {
            break;
        }
    }

    return count;
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
        printf("Could not open file %s\n", dictionary);
        return false;
    }

    char word[LENGTH + 1];
    count_words = 0;
    while(fscanf(file, "%s", word) != EOF) //run till reaching end of the file
    {
        //dma for new ndoe
        node *n = malloc(sizeof(node));
        //checks for null
        if (n == NULL)
        {
            return false;
        }
        //copy string into node using strcpy
        strcpy(n->word, word);
        //call the hash function on the given string
        hash_code = hash(word);

        //insert new node into hash table
        n->next = table[hash_code];
        table[hash_code] = n;
        count_words ++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (count_words > 0)
    {
        return count_words;
    }
    return 0;

}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        //iterate trought every node from hash array
        //in every node go into the list end free its nodes

        node *n = table[i];

        while (n)
        {
            node *tmp = n;
            n = n->next;
            free(tmp);
        }
        if (n == NULL)
        {
            return true;
        }

    }
    return false;
}
