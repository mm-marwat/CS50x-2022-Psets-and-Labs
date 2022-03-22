from cs50 import get_float


def main():
    # Gets input from user : Change owed
    while True:
        n = get_float("Change owed: ")
        if n >= 0:
            break


    # calling on function bellow to calculate and return the minimum coins needed
    print(coins(n))



def coins(cents):
    """Count the minimum amount of coins you need to pay for a specific amount of money"""

    # declare number of coins variable
    coins = 0

    # make cents act like an int so it's more precise
    change = cents * 100

    # count 25c coins
    while change >= 25:
        change = change - 25
        coins = coins + 1

    # count 10c coins
    while change >= 10:
        change = change - 10
        coins = coins + 1

    # count 5c coins
    while change >= 5:
        change = change - 5
        coins = coins + 1

    # count 1c coins
    while change >= 1:
        change = change - 1
        coins = coins + 1

    return coins


if __name__ == "__main__":
    main()
