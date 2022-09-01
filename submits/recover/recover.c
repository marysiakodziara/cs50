#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("incorrect usage, type: ./recover 'file name'");
        return 1;
    }
    FILE *inptr = fopen(argv[argc - 1], "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    //buffer for reading the file
    string buffer[256];
    while (fread (buffer, 2, 256, inptr) == 512)
{
      // DO WHAT YOU NEED HERE
}
}