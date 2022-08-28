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
    int r;
    int g;
    int b;
    int y = 255;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            r = .393 * RGBTRIPLE[i][j].rgbtRed + .769 * RGBTRIPLE[i][j].rgbtGreen + .189 * RGBTRIPLE[i][j].rgbtBlue;
            g = .349 * RGBTRIPLE[i][j].rgbtRed + .686 * RGBTRIPLE[i][j].rgbtGreen + .168 * RGBTRIPLE[i][j].rgbtBlue;
            b = .272 * RGBTRIPLE[i][j].rgbtRed + .534 * RGBTRIPLE[i][j].rgbtGreen + .131 * RGBTRIPLE[i][j].rgbtBlue;
            if (r > y)
            {
                r = y;
            }
            if (g > y)
            {
                g = y;
            }
            if (b > y)
            {
                b = y;
            }
            RGBTRIPLE[i][j].rgbtRed = r;
            RGBTRIPLE[i][j].rgbtGreen = g;
            RGBTRIPLE[i][j].rgbtBlue = b;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int half;
    //checking if weidth is a odd number
    if ((weidth % 2) == 0)
    {
        half = weidth / 2;
    }
    else
    {
        half = 
    }
    int opp;
    for (int i = 0; i < height; i++)
    {
        opp =
        for (int j = 0; j < width; j++)
        {
            int tmp = image[i][j];
            a = b;
            b = tmp;
        }
    }
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
