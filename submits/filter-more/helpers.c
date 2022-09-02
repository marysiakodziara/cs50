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
                                            1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j
                                            + 1].rgbtRed) / 9.0);
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    //implementing a copy of image
    RGBTRIPLE copy[height][width];

    int gx;
    int gy;
    int gxb;
    int gyb;
    int gxg;
    int gyg;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)
            {
                gx = (0 * image[i][j].rgbtRed + 2 * image[i][j + 1].rgbtRed + 0 * image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed);
                gy = (0 * image[i][j].rgbtRed + 0 * image[i][j + 1].rgbtRed + 2 * image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed);
                gxg = (0 * image[i][j].rgbtGreen + 2 * image[i][j + 1].rgbtGreen + 0 * image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen);
                gyg = (0 * image[i][j].rgbtGreen + 0 * image[i][j + 1].rgbtGreen + 2 * image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen);
                gxb = (0 * image[i][j].rgbtBlue + 2 * image[i][j + 1].rgbtBlue + 0 * image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue);
                gyb = (0 * image[i][j].rgbtBlue + 0 * image[i][j + 1].rgbtBlue + 2 * image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue);
            }
            else if (i == 0 && j == (width - 1))
            {
                gx = ((-2) * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 0 * image[i + 1][j].rgbtRed + (-1) * image[i + 1][j - 1].rgbtRed);
                gy = (0 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 2 * image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed);
                gxg = ((-2) * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 0 * image[i + 1][j].rgbtGreen +
                       (-1) * image[i + 1][j - 1].rgbtGreen);
                gyg = (0 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 2 * image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen);
                gxb = ((-2) * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 0 * image[i + 1][j].rgbtBlue + (-1) * image[i + 1][j - 1].rgbtBlue);
                gyb = (0 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 2 * image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue);
            }
            else if (i == 0)
            {
                gx = ((-2) * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 2 * image[i][j + 1].rgbtRed + (-1) * image[i + 1][j - 1].rgbtRed + 0 * image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed);
                gy = (0 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 0 * image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + 2 * image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed);
                gxg = ((-2) * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 2 * image[i][j + 1].rgbtGreen + (-1) * image[i + 1][j - 1].rgbtGreen + 0 * image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen);
                gyg = (0 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 0 * image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + 2 * image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen);
                gxb = ((-2) * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 2 * image[i][j + 1].rgbtBlue + (-1) * image[i + 1][j - 1].rgbtBlue + 0 * image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue);
                gyb = (0 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 0 * image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + 2 * image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue);
            }

            else if (j == (width - 1) && i == (height - 1))
            {
                gx = ((-1) * image[i - 1][j - 1].rgbtRed + 0 * image[i - 1][j].rgbtRed + (-2) * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed);
                gy = ((-1) * image[i - 1][j - 1].rgbtRed + (-2) * image[i - 1][j].rgbtRed + 0 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed);
                gxg = ((-1) * image[i - 1][j - 1].rgbtGreen + 0 * image[i - 1][j].rgbtGreen + (-2) * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen);
                gyg = ((-1) * image[i - 1][j - 1].rgbtGreen + (-2) * image[i - 1][j].rgbtGreen + 0 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen);
                gxb = ((-1) * image[i - 1][j - 1].rgbtBlue + 0 * image[i - 1][j].rgbtBlue + (-2) * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue);
                gyb = ((-1) * image[i - 1][j - 1].rgbtBlue + (-2) * image[i - 1][j].rgbtBlue + 0 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue);
            }
            else if (j == (width - 1))
            {
                gx = ((-1) * image[i - 1][j - 1].rgbtRed + 0 * image[i - 1][j].rgbtRed + (-2)  * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + (-1) * image[i + 1][j - 1].rgbtRed + 0 * image[i + 1][j].rgbtRed);
                gy = ((-1) * image[i - 1][j - 1].rgbtRed + (-2) * image[i - 1][j].rgbtRed + 0 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + image[i + 1][j - 1].rgbtRed + 2 * image[i + 1][j].rgbtRed);
                gxg = ((-1) * image[i - 1][j - 1].rgbtGreen + 0 * image[i - 1][j].rgbtGreen + (-2) * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + (-1) * image[i + 1][j - 1].rgbtGreen + 0 * image[i + 1][j].rgbtGreen);
                gyg = ((-1) * image[i - 1][j - 1].rgbtGreen + (-2) * image[i - 1][j].rgbtGreen + 0 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen + 2 * image[i + 1][j].rgbtGreen);
                gxb = ((-1) * image[i - 1][j - 1].rgbtBlue + 0 * image[i - 1][j].rgbtBlue + (-2) * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + (-1) * image[i + 1][j - 1].rgbtBlue + 0 * image[i + 1][j].rgbtBlue);
                gyb = ((-1) * image[i - 1][j - 1].rgbtBlue + (-2) * image[i - 1][j].rgbtBlue + 0 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue + 2 * image[i + 1][j].rgbtBlue);
            }
            else if (i == (height - 1) && j == 0)
            {
                gx = (0 * image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + 0 * image[i][j].rgbtRed + 2 * image[i][j + 1].rgbtRed);
                gy = ((-2) * image[i - 1][j].rgbtRed + (-1) * image[i - 1][j + 1].rgbtRed + 0 * image[i][j].rgbtRed + 0 * image[i][j + 1].rgbtRed);
                gxg = (0 * image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 2 * image[i][j + 1].rgbtGreen);
                gyg = ((-2) * image[i - 1][j].rgbtGreen + (-1) * image[i - 1][j + 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 0 * image[i][j + 1].rgbtGreen);
                gxb = (0 * image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 2 * image[i][j + 1].rgbtBlue);
                gyb = ((-2) * image[i - 1][j].rgbtBlue + (-1) * image[i - 1][j + 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 0 * image[i][j + 1].rgbtBlue);
            }
            else if (i == (height - 1))
            {
                gx = ((-1) * image[i - 1][j - 1].rgbtRed + 0 * image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + (-2) * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 2 * image[i][j + 1].rgbtRed);
                gy = ((-1) * image[i - 1][j - 1].rgbtRed + (-2) * image[i - 1][j].rgbtRed + (-1) * image[i - 1][j + 1].rgbtRed + 0 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 0 * image[i][j + 1].rgbtRed);
                gxg = ((-1) * image[i - 1][j - 1].rgbtGreen + 0 * image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + (-2) * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 2 * image[i][j + 1].rgbtGreen);
                gyg = ((-1) * image[i - 1][j - 1].rgbtGreen + (-2) * image[i - 1][j].rgbtGreen + (-1) * image[i - 1][j + 1].rgbtGreen + 0 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 0 * image[i][j + 1].rgbtGreen);;
                gxb = ((-1) * image[i - 1][j - 1].rgbtBlue + 0 * image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + (-2) * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 2 * image[i][j + 1].rgbtBlue);
                gyb = ((-1) * image[i - 1][j - 1].rgbtBlue + (-2) * image[i - 1][j].rgbtBlue + (-1) * image[i - 1][j + 1].rgbtBlue + 0 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 0 * image[i][j + 1].rgbtBlue);
            }
            else if (j == 0)
            {
                gx = (0 * image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + 0 * image[i][j].rgbtRed + 2 * image[i][j + 1].rgbtRed + 0 * image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed);
                gy = ((-2) * image[i - 1][j].rgbtRed + (-1) * image[i - 1][j + 1].rgbtRed + 0 * image[i][j].rgbtRed + 0 * image[i][j + 1].rgbtRed + 2 * image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed);
                gxg = (0 * image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 2 * image[i][j + 1].rgbtGreen + 0 * image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen);
                gyg = ((-2) * image[i - 1][j].rgbtGreen + (-1) * image[i - 1][j + 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 0 * image[i][j + 1].rgbtGreen + 2 * image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen);
                gxb = (0 * image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 2 * image[i][j + 1].rgbtBlue + 0 * image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue);
                gyb = ((-2) * image[i - 1][j].rgbtBlue + (-1) * image[i - 1][j + 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 0 * image[i][j + 1].rgbtBlue + 2 * image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue);
            }
            else
            {
                gx = ((-1) * image[i - 1][j - 1].rgbtRed + 0 * image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + (-2) * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 2 * image[i][j + 1].rgbtRed + (-1) * image[i + 1][j - 1].rgbtRed + 0 * image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed);
                gy = ((-1) * image[i - 1][j - 1].rgbtRed + (-2) * image[i - 1][j].rgbtRed + (-1) * image[i - 1][j + 1].rgbtRed + 0 * image[i][j - 1].rgbtRed + 0 * image[i][j].rgbtRed + 0 * image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + 2 * image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed);
                gxg = ((-1) * image[i - 1][j - 1].rgbtGreen + 0 * image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + (-2) * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 2 * image[i][j + 1].rgbtGreen + (-1) * image[i + 1][j - 1].rgbtGreen + 0 * image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen);
                gyg = ((-1) * image[i - 1][j - 1].rgbtGreen + (-2) * image[i - 1][j].rgbtGreen + (-1) * image[i - 1][j + 1].rgbtGreen + 0 * image[i][j - 1].rgbtGreen + 0 * image[i][j].rgbtGreen + 0 * image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + 2 * image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen);
                gxb = ((-1) * image[i - 1][j - 1].rgbtBlue + 0 * image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + (-2) * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 2 * image[i][j + 1].rgbtBlue + (-1) * image[i + 1][j - 1].rgbtBlue + 0 * image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue);
                gyb = ((-1) * image[i - 1][j - 1].rgbtBlue + (-2) * image[i - 1][j].rgbtBlue + (-1) * image[i - 1][j + 1].rgbtBlue + 0 * image[i][j - 1].rgbtBlue + 0 * image[i][j].rgbtBlue + 0 * image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + 2 * image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue);
            }
            if (round(sqrt((gx * gx) + (gy * gy))) > 255)
                {
                    copy[i][j].rgbtRed = 255;
                }
            else
                {
                    copy[i][j].rgbtRed = round(sqrt((gx * gx) + (gy * gy)));
                }
            if (round(sqrt((gxg * gxg * 1.0) + (gyg * gyg * 1.0))) > 255)
                {
                    copy[i][j].rgbtGreen = 255;
                }
            else
                {
                    copy[i][j].rgbtGreen = round(sqrt((gxg * gxg) + (gyg * gyg)));
                }
            if (round(sqrt((gxb * gxb) + (gyb * gyb))) > 255)
                {
                    copy[i][j].rgbtBlue = 255;
                }
            else
                {
                    copy[i][j].rgbtBlue = round(sqrt((gxb * gxb) + (gyb * gyb)));
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
