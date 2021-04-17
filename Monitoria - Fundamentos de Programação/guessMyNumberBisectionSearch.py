print("Please think of a number between 0 and 100!\n")

l = 0
h = 100
found = False

while not found:
    guess = (h+l)//2

    print("Is your secret number " + str(guess)+ "?\n")

    print("Enter 'h' to indicate the guess is too high.")
    print("Enter 'l' to indicate the guess is too low.")
    print("Enter 'c' to indicate I guessed correctly.")

    hint = input("Hint: ")

    if hint == 'c':
        found = True
    elif hint == 'h':
        h = guess
    elif hint == 'l':
        l = guess
    else:
        print("Sorry, I did not understand your input.")

print('Game over. Your secret number was: ' + str(guess))