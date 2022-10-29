def main():
    # calling get_height fn()
    n = get_height()
    for i in range(0, n, 1):
        for j in range(0, n, 1):
            # applying condtionals
            if i + j < n - 1:
                print(" ", end="")
            else:
                print("#", end="")
        print()


# defying a function to check the user input
def get_height():
    while True:
        try:
            # asking for user input
            n = int(input("Height: "))
            # checking the condition
            if n >= 0 and n <= 8:
                # breaking out of loop
                break
        # clarifying an exception
        except ValueError:
            print("Invalid Input")
    return n


# calling maine fn()
main()
