#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;
    for (int i = 0; i < height; i++)
    {
        average = round((RGBTRIPLE[i].rgbtBlue + RGBTRIPLE[i].rgbtGreen + RGBTRIPLE[i].rgbtRed) / 3.0);
        RGBTRIPLE[i].rgbtBlue = average;
        RGBTRIPLE[i].rgbtGreen = average;
        RGBTRIPLE[i].rgbtRed = average;
    }
    for (int j = 0; j < height; j++)
    {
        for (int k = 0; k < width; k++)
        {
            average = round((RGBTRIPLE[j][k].rgbtBlue + RGBTRIPLE[j][k].rgbtGreen + RGBTRIPLE[j][k].rgbtRed) / 3.0);
            RGBTRIPLE[j][k].rgbtBlue = average;
            RGBTRIPLE[j][k].rgbtGreen = average;
            RGBTRIPLE[j][k].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int x
    int y = 255;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            x = .393 * 
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}


    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;
