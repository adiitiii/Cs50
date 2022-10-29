#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float rgb_average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            rgb_average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            if (rgb_average > 255)
            {
                rgb_average = 255; //making average 255 if more than 255
            }
            image[i][j].rgbtBlue = rgb_average;
            image[i][j].rgbtGreen = rgb_average;
            image[i][j].rgbtRed = rgb_average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE originalColor[1][1];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalColor[0][0].rgbtBlue = image[i][j].rgbtBlue;
            originalColor[0][0].rgbtGreen = image[i][j].rgbtGreen;
            originalColor[0][0].rgbtRed = image[i][j].rgbtRed;

            int sepiaBlue = round(.272 * (float)originalColor[0][0].rgbtRed + .534 * (float)originalColor[0][0].rgbtGreen
                                  + .131 * (float)originalColor[0][0].rgbtBlue);
            if (sepiaBlue > 255.0)
            {
                image[i][j].rgbtBlue = 255;

            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }

            int sepiaGreen = round(.349 * (float)originalColor[0][0].rgbtRed + .686 * (float)originalColor[0][0].rgbtGreen
                                   + .168 * (float)originalColor[0][0].rgbtBlue);
            if (sepiaGreen > 255.0)
            {
                image[i][j].rgbtGreen = 255;

            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

            int sepiaRed = round(.393 * (float)originalColor[0][0].rgbtRed + .769 * (float)originalColor[0][0].rgbtGreen
                                 + .189 * (float)originalColor[0][0].rgbtBlue);
            if (sepiaRed > 255.0)
            {
                image[i][j].rgbtRed = 255;

            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
        }
    }
    return;
}



// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy_img[height][width]; //temporary image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy_img[i][j] = image[i][j]; //copying the original image
        }
    }
    float blue_avg;
    float green_avg;
    float red_avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // For all four corners
            if (i == 0 && j == 0) //top left corner
            {
                blue_avg = (copy_img[i][j].rgbtBlue + copy_img[i][j + 1].rgbtBlue + copy_img[i + 1][j].rgbtBlue
                            + copy_img[i + 1][j + 1].rgbtBlue);
                blue_avg = round(blue_avg / 4.0);
                if (blue_avg > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = blue_avg;
                }

                green_avg = (copy_img[i][j].rgbtGreen + copy_img[i][j + 1].rgbtGreen + copy_img[i + 1][j].rgbtGreen
                             + copy_img[i + 1][j + 1].rgbtGreen);
                green_avg = round(green_avg / 4.0);
                if (green_avg > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = green_avg;
                }

                red_avg = (copy_img[i][j].rgbtRed + copy_img[i][j + 1].rgbtRed + copy_img[i + 1][j].rgbtRed
                           + copy_img[i + 1][j + 1].rgbtRed);
                red_avg = (red_avg / 4.0);
                if (red_avg > 255)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = red_avg;
                }
            }

            else if (i == 0 && j == (width - 1)) //top right corner
            {
                blue_avg = (copy_img[i][j - 1].rgbtBlue + copy_img[i][j].rgbtBlue + copy_img[i + 1][j - 1].rgbtBlue
                            + copy_img[i + 1][j].rgbtBlue);
                blue_avg = round(blue_avg / 4.0);
                if (blue_avg > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = blue_avg;
                }

                green_avg = (copy_img[i][j - 1].rgbtGreen + copy_img[i][j].rgbtGreen + copy_img[i + 1][j - 1].rgbtGreen
                             + copy_img[i + 1][j].rgbtGreen);
                green_avg = round(green_avg / 4.0);
                if (green_avg > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = green_avg;
                }

                red_avg = (copy_img[i][j - 1].rgbtRed + copy_img[i][j].rgbtRed + copy_img[i + 1][j - 1].rgbtRed
                           + copy_img[i + 1][j].rgbtRed);
                red_avg = round(red_avg / 4.0);
                if (red_avg > 255)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = red_avg;
                }
            }

            else if (i == (height - 1) && j == 0) //bottom left corner
            {
                blue_avg = (copy_img[i - 1][j].rgbtBlue + copy_img[i - 1][j + 1].rgbtBlue + copy_img[i][j].rgbtBlue
                            + copy_img[i][j + 1].rgbtBlue);
                blue_avg = round(blue_avg / 4.0);
                if (blue_avg > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = blue_avg;
                }

                green_avg = (copy_img[i - 1][j].rgbtGreen + copy_img[i - 1][j + 1].rgbtGreen + copy_img[i][j].rgbtGreen
                             + copy_img[i][j + 1].rgbtGreen);
                green_avg = round(green_avg / 4.0);
                if (green_avg > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = green_avg;
                }

                red_avg = (copy_img[i - 1][j].rgbtRed + copy_img[i - 1][j + 1].rgbtRed + copy_img[i][j].rgbtRed
                           + copy_img[i][j + 1].rgbtRed);
                red_avg = round(red_avg / 4.0);
                if (red_avg > 255)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = red_avg;
                }
            }

            else if (i == (height - 1) && j == (width - 1)) //bottom right corner
            {
                blue_avg = (copy_img[i - 1][j - 1].rgbtBlue + copy_img[i - 1][j].rgbtBlue + copy_img[i][j - 1].rgbtBlue
                            + copy_img[i][j].rgbtBlue);
                blue_avg = round(blue_avg / 4.0);
                if (blue_avg > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = blue_avg;
                }

                green_avg = (copy_img[i - 1][j - 1].rgbtGreen + copy_img[i - 1][j].rgbtGreen + copy_img[i][j - 1].rgbtGreen
                             + copy_img[i][j].rgbtGreen);
                green_avg = round(green_avg / 4.0);
                if (green_avg > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = green_avg;
                }

                red_avg = (copy_img[i - 1][j - 1].rgbtRed + copy_img[i - 1][j].rgbtRed + copy_img[i][j - 1].rgbtRed
                           + copy_img[i][j].rgbtRed);
                red_avg = round(red_avg / 4.0);
                if (red_avg > 255)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = red_avg;
                }
            }

            // For all four edges
            else if (i == 0 && j > 0 && j < (width - 1)) //top edge
            {
                blue_avg = (copy_img[i][j - 1].rgbtBlue + copy_img[i][j].rgbtBlue + copy_img[i][j + 1].rgbtBlue
                            + copy_img[i + 1][j - 1].rgbtBlue + copy_img[i + 1][j].rgbtBlue + copy_img[i + 1][j + 1].rgbtBlue);
                blue_avg = round(blue_avg / 6.0);
                if (blue_avg > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = blue_avg;
                }

                green_avg = (copy_img[i][j - 1].rgbtGreen + copy_img[i][j].rgbtGreen + copy_img[i][j + 1].rgbtGreen
                             + copy_img[i + 1][j - 1].rgbtGreen + copy_img[i + 1][j].rgbtGreen + copy_img[i + 1][j + 1].rgbtGreen);
                green_avg = round(green_avg / 6.0);
                if (green_avg > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = green_avg;
                }

                red_avg = (copy_img[i][j - 1].rgbtRed + copy_img[i][j].rgbtRed + copy_img[i][j + 1].rgbtRed
                           + copy_img[i + 1][j - 1].rgbtRed + copy_img[i + 1][j].rgbtRed + copy_img[i + 1][j + 1].rgbtRed);
                red_avg = round(red_avg / 6.0);
                if (red_avg > 255)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = red_avg;
                }
            }

            else if (j == 0 && i > 0 && i < (height - 1)) //left edge
            {
                blue_avg = (copy_img[i - 1][j].rgbtBlue + copy_img[i - 1][j + 1].rgbtBlue + copy_img[i][j].rgbtBlue
                            + copy_img[i][j + 1].rgbtBlue + copy_img[i + 1][j].rgbtBlue + copy_img[i + 1][j + 1].rgbtBlue);
                blue_avg = round(blue_avg / 6.0);
                if (blue_avg > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = blue_avg;
                }

                green_avg = (copy_img[i - 1][j].rgbtGreen + copy_img[i - 1][j + 1].rgbtGreen + copy_img[i][j].rgbtGreen
                             + copy_img[i][j + 1].rgbtGreen + copy_img[i + 1][j].rgbtGreen + copy_img[i + 1][j + 1].rgbtGreen);
                green_avg = round(green_avg / 6.0);
                if (green_avg > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = green_avg;
                }

                red_avg = (copy_img[i - 1][j].rgbtRed + copy_img[i - 1][j + 1].rgbtRed + copy_img[i][j].rgbtRed
                           + copy_img[i][j + 1].rgbtRed + copy_img[i + 1][j].rgbtRed + copy_img[i + 1][j + 1].rgbtRed);
                red_avg = round(red_avg / 6.0);
                if (red_avg > 255)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = red_avg;
                }
            }

            else if (j == (width - 1) && i > 0 && i < (height - 1)) //right edge
            {
                blue_avg = (copy_img[i - 1][j - 1].rgbtBlue + copy_img[i - 1][j].rgbtBlue + copy_img[i][j - 1].rgbtBlue
                            + copy_img[i][j].rgbtBlue + copy_img[i + 1][j - 1].rgbtBlue + copy_img[i + 1][j].rgbtBlue);
                blue_avg = round(blue_avg / 6.0);
                if (blue_avg > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = blue_avg;
                }

                green_avg = (copy_img[i - 1][j - 1].rgbtGreen + copy_img[i - 1][j].rgbtGreen + copy_img[i][j - 1].rgbtGreen
                             + copy_img[i][j].rgbtGreen + copy_img[i + 1][j - 1].rgbtGreen + copy_img[i + 1][j].rgbtGreen);
                green_avg = round(green_avg / 6.0);
                if (green_avg > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = green_avg;
                }

                red_avg = (copy_img[i - 1][j - 1].rgbtRed + copy_img[i - 1][j].rgbtRed + copy_img[i][j - 1].rgbtRed
                           + copy_img[i][j].rgbtRed + copy_img[i + 1][j - 1].rgbtRed + copy_img[i + 1][j].rgbtRed);
                red_avg = round(red_avg / 6.0);
                if (red_avg > 255)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = red_avg;
                }
            }

            else if (i == (height - 1) && j > 0 && j < (width - 1)) //bottom edge
            {
                blue_avg = (copy_img[i - 1][j - 1].rgbtBlue + copy_img[i - 1][j].rgbtBlue + copy_img[i - 1][j + 1].rgbtBlue
                            + copy_img[i][j - 1].rgbtBlue + copy_img[i][j].rgbtBlue + copy_img[i][j + 1].rgbtBlue);
                blue_avg = round(blue_avg / 6.0);
                if (blue_avg > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = blue_avg;
                }

                green_avg = (copy_img[i - 1][j - 1].rgbtGreen + copy_img[i - 1][j].rgbtGreen + copy_img[i - 1][j + 1].rgbtGreen
                             + copy_img[i][j - 1].rgbtGreen + copy_img[i][j].rgbtGreen + copy_img[i][j + 1].rgbtGreen);
                green_avg = round(green_avg / 6.0);
                if (green_avg > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = green_avg;
                }

                red_avg = (copy_img[i - 1][j - 1].rgbtRed + copy_img[i - 1][j].rgbtRed + copy_img[i - 1][j + 1].rgbtRed
                           + copy_img[i][j - 1].rgbtRed + copy_img[i][j].rgbtRed + copy_img[i][j + 1].rgbtRed);
                red_avg = round(red_avg / 6.0);
                if (red_avg > 255)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = red_avg;
                }
            }

            // For Middle Pixels
            else
            {
                blue_avg = (copy_img[i - 1][j - 1].rgbtBlue + copy_img[i - 1][j].rgbtBlue + copy_img[i - 1][j + 1].rgbtBlue
                            + copy_img[i][j - 1].rgbtBlue + copy_img[i][j].rgbtBlue + copy_img[i][j + 1].rgbtBlue
                            + copy_img[i + 1][j - 1].rgbtBlue + copy_img[i + 1][j].rgbtBlue + copy_img[i + 1][j + 1].rgbtBlue);
                blue_avg = round(blue_avg / 9.0);
                if (blue_avg > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = blue_avg;
                }

                green_avg = (copy_img[i - 1][j - 1].rgbtGreen + copy_img[i - 1][j].rgbtGreen + copy_img[i - 1][j + 1].rgbtGreen
                             + copy_img[i][j - 1].rgbtGreen + copy_img[i][j].rgbtGreen + copy_img[i][j + 1].rgbtGreen
                             + copy_img[i + 1][j - 1].rgbtGreen + copy_img[i + 1][j].rgbtGreen + copy_img[i + 1][j + 1].rgbtGreen);
                green_avg = round(green_avg / 9.0);
                if (green_avg > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = green_avg;
                }

                red_avg = (copy_img[i - 1][j - 1].rgbtRed + copy_img[i - 1][j].rgbtRed + copy_img[i - 1][j + 1].rgbtRed
                           + copy_img[i][j - 1].rgbtRed + copy_img[i][j].rgbtRed + copy_img[i][j + 1].rgbtRed
                           + copy_img[i + 1][j - 1].rgbtRed + copy_img[i + 1][j].rgbtRed + copy_img[i + 1][j + 1].rgbtRed);
                red_avg = round(red_avg / 9.0);
                if (red_avg > 255)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = red_avg;
                }
            }
        }
    }
    return;
}
