#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;

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
            r = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            g = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            b = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
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
    if ((width % 2) == 0)
    {
        half = (width / 2);
    }
    else
    {
        half = round(width / 2);
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
                RGBTRIPLE tmp = image[i][j];
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
    int r;
    int g;
    int b;

    //implementing a copy of image
    RGBTRIPLE copy[height][width];

    //making copy of blurred pixels into copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)
            {
                copy[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) /
                                           4.0);
                copy[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j +
                                              1].rgbtGreen) / 4.0);
                copy[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j +
                                             1].rgbtBlue) / 4.0);
            }
            else if (i == 0 && j == (width - 1))
            {
                copy[i][j].rgbtRed = round((image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed) /
                                           4.0);
                copy[i][j].rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j -
                                              1].rgbtGreen) / 4.0);
                copy[i][j].rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j -
                                             1].rgbtBlue) / 4.0);
            }
            else if (i == 0)
            {
                copy[i][j].rgbtRed = round((image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed +
                                            image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.0);
                copy[i][j].rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j -
                                              1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.0);
                copy[i][j].rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j -
                                             1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.0);
            }
            else if (j == (width - 1) && i == (height - 1))
            {
                copy[i][j].rgbtRed = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed) /
                                           4.0);
                copy[i][j].rgbtGreen = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen +
                                              image[i][j].rgbtGreen) / 4.0);
                copy[i][j].rgbtBlue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j - 1].rgbtBlue +
                                             image[i][j].rgbtBlue) / 4.0);
            }
            else if (j == (width - 1))
            {
                copy[i][j].rgbtRed = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed +
                                            image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / 6.0);
                copy[i][j].rgbtGreen = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen +
                                              image[i][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 6.0);
                copy[i][j].rgbtBlue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j - 1].rgbtBlue +
                                             image[i][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 6.0);
            }
            else if (i == (height - 1) && j == 0)
            {
                copy[i][j].rgbtRed = round((image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed) /
                                           4.0);
                copy[i][j].rgbtGreen = round((image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j +
                                              1].rgbtGreen) / 4.0);
                copy[i][j].rgbtBlue = round((image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j +
                                             1].rgbtBlue) / 4.0);
            }
            else if (i == (height - 1))
            {
                copy[i][j].rgbtRed = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j -
                                            1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed) / 6.0);
                copy[i][j].rgbtGreen = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j
                                              - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen) / 6.0);
                copy[i][j].rgbtBlue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j -
                                             1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue) / 6.0);
            }
            else if (j == 0)
            {
                copy[i][j].rgbtRed = round((image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                            image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.0);
                copy[i][j].rgbtGreen = round((image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j +
                                              1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.0);
                copy[i][j].rgbtBlue = round((image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j +
                                             1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.0);
            }
            else
            {
                copy[i][j].rgbtRed = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j -
                                            1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].r
                                            gbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 9.0);
                copy[i][j].rgbtGreen = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j
                                              - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image
                                              [i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 9.0);
                copy[i][j].rgbtBlue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j -
                                             1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1]
                                             [j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 9.0);
            }
        }
    }

    //rewriting blured picture into image
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l].rgbtRed = copy[k][l].rgbtRed;
            image[k][l].rgbtGreen = copy[k][l].rgbtGreen;
            image[k][l].rgbtBlue = copy[k][l].rgbtBlue;
        }
    }
    return;
}