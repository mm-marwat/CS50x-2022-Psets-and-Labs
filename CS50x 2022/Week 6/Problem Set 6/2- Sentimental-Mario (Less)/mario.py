from cs50 import get_int

# Making sure the number is a positive integer between 1 and 9
while True:
    n = get_int("Height: ")
    if 9 > n >= 1:
        break

# iterating through a reverse-orderd list to first insert spaces than hashes
for i in reversed(range(n)):
    print((" " * i) + ("#" * (n - i)))
