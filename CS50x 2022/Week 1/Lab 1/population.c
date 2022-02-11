#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start, end;

    // Prompt for start size and making sure the number is greater than 9
    do
    {
        start = get_int("Start Size: ");
    }
    while (start < 9);

    // Prompt for end size and making sure the number is greater than start size
    do
    {
        end = get_int("End Size: ");
    }
    while (end < start);

    // Calculate number of years until we reach threshold
    int years = 0;
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }

    // Print number of years
    printf("%i\n", years);
}
