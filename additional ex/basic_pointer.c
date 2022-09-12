#include <stdio.h>

int main(void)
{
    int m = 10;
    int *z = &m;
    printf("z stores the address of m  = %p\n", z);

    return 0;
}