#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

// Getting the amount of cents and making sure it's a positive number
int get_cents(void)
{
    int cents;

    do
    {
        cents = get_int("Enter the number of cents you need change for: ");
    }
    while (cents < 0);

    return cents;
}


int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25) // Runs untill the amount of cents >= to a quarter and in the end of each loop add one quarter to the coins
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10) // Runs untill the amount of cents >= to a dime and in the end of each loop add one dime to the coins
    {
        dimes++;
        cents = cents - 10;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5) // Runs untill the amount of cents >= to a nickel and in the end of each loop add one nickel to the coins
    {
        nickels++;
        cents = cents - 5;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    int pennies = 0;
    while (cents >= 1) //Runs untill the amount of cents >= to a penny and in the end of each loop add one penny to the coins
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;
}
