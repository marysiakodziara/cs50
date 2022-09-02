#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("incorrect usage, type: ./recover 'file name'\n");
        return 1;
    }
    FILE* file = fopen(argv[argc - 1], "r");
    if (file == NULL)
    {
        printf("Could not open the file.\n");
        return 1;
    }

    //number of read jpegs
    int j_count = 0;

    //buffer for reading the file
    unsigned char buffer[512];
    char filename[512];

    FILE* img = NULL;
    while (fread (buffer, 1, 512, file) == 512)
    {

            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                if (j_count == 0)
                {
                    j_count += 1;
                    sprintf(filename, "%03i.jpg", j_count);
                    img = fopen(filename, "w");
                    fwrite(buffer, 1 ,512, img);
                }
            }

    }
}


