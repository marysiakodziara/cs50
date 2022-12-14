#include <stdio.h>

int main(void)
{
    int m = 29;

    printf("Address of m : %p\nValue of m : %i\n", &m, m);

    int *ab = &m;

    printf("Now ab is assigned with the address of m.\nAddress of pointer ab : %p\nContent of pointer ab : %i\n", ab, *ab);

    m = 34;

    printf("The value of m assigned to 34 now.\nAddress of pointer ab : %p\nContent of pointer ab : %i\n", ab, *ab);

    *ab = 7;

    printf("The pointer variable ab is assigned with the value 7 now.\nAddress of m : %p\nValue of m : %i\n", &m, m);

    return 1;
}