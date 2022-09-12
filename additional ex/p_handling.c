#include <stdio.h>

int main(void)
{
    int m = 29;

    printf("Address of m : %p\nValue of m : %i\n", &m, m);

    int *ab = &m;

    printf("Now ab is assigned with the address of m.\nAddress of pointer ab : %p\nContent of pointer ab : %i\n", *ab, ab);

}