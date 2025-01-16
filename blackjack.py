import random

cards = [
            2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 
            2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,     
            2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,     
            2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11  
        ]

playerHand = []
dealerHand = []
userChoice = 1

print("~~~~~~~~~~~~~~~~~~ Welcome to Blackjack ~~~~~~~~~~~~~~~~~~")

while userChoice == 1:
    for i in range(0,2):
        playerHand.append(random.choice(cards))
        dealerHand.append(random.choice(cards))

    print(f"This is one of the dealer's cards: {dealerHand[0]}")
    print(f"These are your cards: {playerHand[0]}, {playerHand[1]}")

    print()
    userChoice = int(input("Hit(1) or Stay(2)? "))

    while userChoice == 1:
        playerHand.append(random.choice(cards))
        print(f"This is the card you just got: {playerHand[-1]}")
        print()

        if playerHand[-1] == 11:
            userChoice = int(input("Do you want to change the 11 to a 1? Yes(1) or No(2): "))

            if userChoice == 1:
                playerHand[-1] = 1
        
        print()
        print(f"These are your cards: {playerHand}")
        userChoice = int(input("Hit(1) or Stay(2)? "))

    dealerSum = sum(dealerHand)

    while dealerSum < 17:
        dealerHand.append(random.choice(cards))
        dealerSum = sum(dealerHand)

        if dealerHand[-1] == 11 and (dealerSum > 17 or dealerSum > 21):
            dealerHand[-1] = 1

        dealerSum = sum(dealerHand)

    playerSum = sum(playerHand)

    print()
    print(f"These are the dealer's cards: {dealerHand}")
    print(f"These are your cards: {playerHand}")
    print()

    if (playerSum > dealerSum and playerSum < 21) or playerSum == 21 or (dealerSum > 21 and playerSum < 21):
        print("Congratulations, You Win!")

    elif playerSum < dealerSum or playerSum > 21:
        print("Oops, you lose....")
    
    elif playerSum == dealerSum:
        print("It's a Tie!!!")

    print()
    userChoice = int(input("Play again? Yes(1) or No(2): "))
    print()

    playerHand.clear()
    dealerHand.clear()