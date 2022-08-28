#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;
    for (int i = 0; i < height; i++)
    {
        average = round((image[i].rgbtBlue + image[i].rgbtGreen + image[i].rgbtRed) / 3.0);
        image[i].rgbtBlue = average;
        image[i].rgbtGreen = average;
        image[i].rgbtRed = average;
    }
    for (int j = 0; j < height; j++)
    {
        for (int k = 0; k < width; k++)
        {
            average = round((image[j][k].rgbtBlue + image[j][k].rgbtGreen + image[j][k].rgbtRed) / 3.0);
            image[j][k].rgbtBlue = average;
            image[j][k].rgbtGreen = average;
            image[j][k].rgbtRed = average;
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
            r = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            g = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            b = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
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
            image[i][j].rgbtRed = r;
            image[i][j].rgbtGreen = g;
            image[i][j].rgbtBlue = b;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int half;
    //checking if weidth is a odd number to calculate
    //how many times the nested loop should iterate
    if ((weidth % 2) == 0)
    {
        half = (width / 2);
    }
    else
    {
        half = round(width/2);
    }
    //integer that will count down in the nested loop
    int opp;

    for (int i = 0; i < height; i++)
    {
        opp = width - 1;
        for (int j = 0; j < half; j++)
        {
            if (j < opp)
            {
                int tmp = image[i][j];
                image[i][j] = image[i][opp];
                image[i][opp] = tmp;
            }
            opp--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //implementing a copy of image
    RGBTRIPLE copy[height][width];
    return;
}


    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;
