#include <stdio.h>

int main(void)
{
    int m = 300;
    float fx = 300.60006;
    char cht = 'z';

    printf("Pointer : Demonstrate the use of & and * operator :\n");
    printf("--------------------------------------------------------\n");
    printf("m = %i\nfx = %f\ncht = %c\n", m, fx, cht);

    printf("Using & operator :\n");
    printf("-----------------------\n");
    printf("address of m = %p\naddress of fx = %p\naddress of cht = %p\n", &m, &fx, &cht);

    printf("Using & and * operator :\n");
    printf("-----------------------------\n");
    printf("value at address of m = %i\nvalue at address of fx = %f\nvalue at address of cht = %c\n", *&m, *&fx, *&cht);

    return 1;
}