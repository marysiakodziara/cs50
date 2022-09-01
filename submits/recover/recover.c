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

    //number of read jpegs
    int j_count = 0;

    //buffer for reading the file
    char buffer[512];

    while (fread (buffer, 1, 512, inptr) == 512)
    {
        for (int i = 0; i < 512; i++)
        {
            if (buffer[i] == 0xff, buffer[i + 1] == 0xd8, buffer[i + 2] == 0xff, (buffer[i + 3] & 0xf0) == 0xe0 )
            {
                int j_count += 1;
                sprintf(filename, "%03i.jpg, j_count)
            }
        }
    }
}