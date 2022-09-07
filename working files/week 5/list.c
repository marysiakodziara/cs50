#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //dynamically allocate an array of size 3
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    //assign three numbers to that array
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    //resize new array to be of size 4
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        return 1;
    }

    //copy numbers from old array into new array
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }

    //add fourth number to new array
    tmp[3] = 4;

    //remember new array
    list = tmp;

    //print new array
    for(int  k = 0; k < 4; k++)
    {
        printf("%i\n", list[k]);
    }

    //free array
    free(list);
    return 0;


}