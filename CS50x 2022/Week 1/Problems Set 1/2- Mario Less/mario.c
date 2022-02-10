#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Declaring a vaiable to store user-enterd number
    int height;

    // Validating the number to be in between 1-8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Creating Pyramids
    for (int row = 0; row < height; row++)
    {
        for (int space = 0; space < height - row - 1; space++) //adding spaces before hashes in a right-aligned pyramid
        {
            printf(" ");
        }
        for (int column = 0; column <= row; column++) //adding hashes
        {
            printf("#");
        }
        printf("\n"); // making new line after each rows
    }
}
