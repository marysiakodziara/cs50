#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    string text = get_string("Write text sample: ");
    printf("%s\n", text);
}