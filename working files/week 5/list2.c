#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    //list of size
    node *list = NULL;

    //add a number to list
    node *n = maloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->numberm = 1;
    n->next = NULL;

    //update list to point to new node
    list = n;

    //add a number to list
    n = maloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    //add a number to list
    n = maloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    //print numbers
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number)
    }

    //free list
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }

    return 0;
}
p->parents[0] = parent0;
        p->parents[1] = parent1;



//old hash
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
        }
        else
        {
            break;
        }
    }

    return count;


    //yt hash
    unsigned long total = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }
    return total % N;