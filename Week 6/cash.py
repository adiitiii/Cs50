# Import get_float from cs50 liabrary
from cs50 import get_float

# looping to make sure input is greater than 0
while True:
    cents = get_float("Change owed: ")
    if cents > 0:
        break

# rounding the user inputted digit
coins = round(int(cents*100))

# for every coin sorted
count = 0

while coins > 0:
    if coins >= 25:
        count += 1
        coins -= 25

    elif coins >= 10:
        count += 1
        coins -= 10

    elif coins >= 5:
        count += 1
        coins -= 5

    elif coins >= 1:
        coins -= 1
        count += 1

print(count)
