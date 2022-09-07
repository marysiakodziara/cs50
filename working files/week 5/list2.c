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
    n->
}