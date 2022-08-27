// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file

    char* arr = malloc(sizeof(HEADER_SIZE));
    fread(arr, sizeof(char), HEADER_SIZE, input);
    fwrite(arr, sizeof(char), HEADER_SIZE, output);
    free(arr);

    // TODO: Read samples from input file and write updated data to output file
    char* arr2 = malloc(2);
    while(*arr != EOF)
    {
       fread(arr2, sizeof(char), 2, input);
       arr2[0] = arr2[0] * factor;
       arr2[1] = arr2[1] * factor;
       fwrite(arr2, sizeof(char), 2, output);
    }
    free(arr2);

    // Close files
    fclose(input);
    fclose(output);
    return 0;
}
