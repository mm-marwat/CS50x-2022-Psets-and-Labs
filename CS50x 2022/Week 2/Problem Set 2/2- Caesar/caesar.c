#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char letter, int k);

int main(int argc, string argv[])
{
    // Making sure the user is entering the right amount of argument and notify when the user is makin error
    if (argc == 2)
    {
        if (only_digits(argv[1])) // this only run when the user type integer in commond line
        {
            int k = atoi(argv[1]);
            string text = get_string("Plaintext: ");

            printf("ciphertext: ");
            for (int i = 0; i < strlen(text); i++) // looping throgh the text and changing each letter by provide key
            {
                char rotated_letter = rotate(text[i], k);
                printf("%c", rotated_letter);
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n"); // if the user put non-integer value in the commond line
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n"); // if the commond line has more than two argument; other than the program name and integer we ask user to enter
        return 1;
    }
}


// This function returns true if a string contains all integer otherwise it returns false
bool only_digits(string s)
{
    bool digit = false;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] < 48 || s[i] > 58)
        {
            digit = false;
        }
        else
        {
            digit = true;
        }
    }
    return digit;
}


// This function take one char and an integer and then return the char rotated the interger times
char rotate(char letter, int k)
{
    char rotated_letter;

    if (islower(letter))
    {
        rotated_letter = ((letter + k) - 97) % 26 + 97;
    }
    else if (isupper(letter))
    {
        rotated_letter = ((letter + k) - 65) % 26 + 65;
    }
    else
    {
        rotated_letter = letter;
    }
    return rotated_letter;
}
