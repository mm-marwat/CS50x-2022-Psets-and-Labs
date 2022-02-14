#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letter(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text;
    text = get_string("Text: ");

    int letters = count_letter(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = ((float) letters / (float) words) * 100; // Finding the value of (L) in Coleman-Liau index formula
    float S = ((float) sentences / (float) words) * 100; // Finding the value of (S) in Coleman-Liau index formula
    double index = (0.0588 * L) - (0.296 * S) - 15.8; //Calculating the value of Coleman-Liau index

    if ((int) round(index) < 1)
    {
        printf("Before Grade 1\n"); // If the Coleman-Liau index is less than 1
    }
    else if ((int) round(index) > 16)
    {
        printf("Grade 16+\n"); // If the Coleman-Liau index is greater than 16
    }
    else
    {
        printf("Grade %i\n", (int) round(index)); // If the Coleman-Liau index is in between 1 and 16
    }
}

// Counting the amount of letters in a text
int count_letter(string text)
{
    int text_length = strlen(text);
    int number_of_letters = 0;
    for (int i = 0; i < text_length; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            number_of_letters++;
        }
    }
    return number_of_letters;
}

// Countring the amount of words in a text
int count_words(string text)
{
    int number_of_words = 1;
    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == 32)
        {
            number_of_words++;
        }
    }
    return number_of_words;
}

// Counting the amount fo sentences in a text
int count_sentences(string text)
{
    int number_of_sentences = 0;
    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            number_of_sentences++;
        }
    }
    return number_of_sentences;
}
