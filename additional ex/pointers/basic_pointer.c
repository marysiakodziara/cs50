#include <stdio.h>

int main(void)
{
    int m = 10;
    int *z = &m;
    int n;
    int o;

    printf("Pointer : Show the basic declaration of pointer:\n");
    printf("-------------------------------------------------\n");
    printf("z stores the address of m  = %p\n", z);
    printf("*z stores the value of m = %i\n", *z);
    printf("&m is the address of m = %p\n", &m);
    printf("&n stores the address of n = %p\n", &n);
    printf("&o  stores the address of o = %p\n", &o);
    printf("&z stores the address of z = %p\n", &z);

    return 0;
}