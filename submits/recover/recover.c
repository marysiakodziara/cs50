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
    FILE *inptr = fopen(argv[argc - 1], "r");
    if (inptr == NULL)
    {
        printf("Could not open the file.\n");
        return 1;
    }

    //number of read jpegs
    int j_count = 0;

    //buffer for reading the file
    char buffer[512];
    string filename;

    while (fread (buffer, 1, 512, inptr) == 512)
    {
        for (int i = 0; i < 512; i++)
        {
            if (buffer[i] == 0xff, buffer[i + 1] == 0xd8, buffer[i + 2] == 0xff, (buffer[i + 3] & 0xf0) == 0xe0)
            {
                int j_count += 1;
                sprintf(filename, "%03i.jpg", j_count)
                FILE *img = fopen(filename, "w");
                int k = i;
                while ((buffer[k] != 0xff && buffer[k + 1] != 0xd8 && buffer[k + 2] != 0xff && (buffer[k + 3] & 0xf0) != 0xe0) && k < 512)
                {
                    fwrite(buffer[k], 1, 1, filename);
                    k++;
                }
                flose(filename);

            }
            else if (j_count != 0)
            {
                FILE *img = fopen(filename, "w");
                int k = i;
                while ((buffer[k] != 0xff && buffer[k + 1] != 0xd8 && buffer[k + 2] != 0xff && (buffer[k + 3] & 0xf0) != 0xe0) && k < 512)
                {
                    fwrite(buffer[k], 1, 1, filename);
                    k++;
                }
                flose(filename);
            }
        }
    }
    flose(filename);
}


