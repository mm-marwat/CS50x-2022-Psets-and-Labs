#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height; // Declaring a varible to store the number user enters as a height

    do
    {
        height = get_int("Height: "); //Prompting the user to enter the height after which the (do while) loop will make sure the number is in between 1 and 8
    }
    while (height < 1 || height > 8);

    for (int row = 0; row < height; row++) //Keeping track of rows
    {
        for (int space = 0; space < height - row - 1; space++) //Adding space before hashes in the left-aligned pyramid
        {
            printf(" ");
        }
        for (int column_left = 0; column_left <= row; column_left++) //Creating the left-aligned pyramid
        {
            printf("#");
        }

        printf("  "); //Adding TWO spaces in between the left-aligned and right-aligned pyramids

        for (int column_right = 0; column_right <= row; column_right++) //Creating right-aligned pyramid
        {
            printf("#");
        }
        printf("\n"); //Adding new line after each row
    }
}
