// cpp input output operations
#include <iostream>

// srand and rand
#include <cstdlib>

// used for srand
#include <ctime>

// used for dynamically sized arrays
#include <vector>

// used for summing the vectors
#include <numeric>

int main(){
    srand(time(0));
    int cards[] = {
                    2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 
                    2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,     
                    2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,     
                    2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11  
                  };    
    std::vector <int> playerHand;   
    std::vector <int> dealerHand;
    int userChoice;
    int cardChoice;
    int play;
    std::cout << "~~~~~~~~~~~~~~~~~~ Welcome to Blackjack ~~~~~~~~~~~~~~~~~~\n";
    
    // do while for game loop
    do{
        // hands out two random cards for the player and dealer
        for(int i = 0; i < 2; i++){
            cardChoice = rand() % 52;
            playerHand.push_back(cards[cardChoice]);

            cardChoice = rand() % 52;
            dealerHand.push_back(cards[cardChoice]);
        }

        // shows one of the dealer's cards, shows both of the player's cards
        // then ask to draw another(hit) or stay with the same cards(stay)
        std::cout << "This is one of the dealers cards: " << dealerHand.at(1) << "\n";
        
        std::cout << "These are your cards: " << playerHand.at(0) << " " << playerHand.at(1) << "\n";

        std::cout << "Hit(1) or stay(2)? ";
        std::cin >> userChoice;

        std::cout << "\n";
        
        // while the player wants to hit, draw cards
        while(userChoice == 1){
            cardChoice = rand() % 52;
            playerHand.push_back(cards[cardChoice]);

            std::cout << "This is the card you just got: " << cards[cardChoice];
            
            std::cout << "\n";

            // if the card is 11, the player has the choice to change it 
            // to an 11 or a 1 based on the sum of the cards
            if(cards[cardChoice] == 11){
                std::cout << "Do you want to change the 11 to a 1? Yes(1) or No(2): ";
                std::cin >> userChoice;
                if(userChoice = 1){
                    playerHand[playerHand.size()-1] = 1;
                }
            }
            
            std::cout << "\n";
            
            // displays the player's cards, then asks to hit or stay
            std::cout << "These are your cards: ";
                for(int i = 0; i < playerHand.size(); i++){
                    std::cout << playerHand.at(i) << " ";
                }

            std::cout << "\nHit(1) or stay(2)? ";
            std::cin >> userChoice;
            std::cout << "\n";
        }

        // sums the dealer's cards
        int dealerSum = std::reduce(dealerHand.begin(), dealerHand.end(), 0);

        // while the sum of the cards that the dealer has is less than 17,
        // keep drawing and when one of the cards is 11 and the sum is greater than 17 or 21,
        // change the 11 to a one
        while(dealerSum < 17){
            cardChoice = rand() % 52;
            dealerHand.push_back(cards[cardChoice]);
            dealerSum = std::reduce(dealerHand.begin(), dealerHand.end(), 0);

            if(dealerHand.at(dealerHand.size()-1) == 11 && (dealerSum > 17 || dealerSum > 21)){
                dealerHand.at(dealerHand.size()-1) = 1;
            }
            dealerSum = std::reduce(dealerHand.begin(), dealerHand.end(), 0);
        }

        dealerSum = std::reduce(dealerHand.begin(), dealerHand.end(), 0);

        // sums the player's cards
        int playerSum = std::reduce(playerHand.begin(), playerHand.end(), 0);

        // shows the dealer's and the player's cards
        std::cout << "This is the dealer's cards: ";
        for(int i = 0; i < dealerHand.size(); i++){
                std::cout << dealerHand.at(i) << " ";
        }

        std::cout << "\nThese are your cards: ";
        for(int i = 0; i < playerHand.size(); i++){
                std::cout << playerHand.at(i) << " ";
        }

        //when the player's sum is greater than the dealer's sum and less than 21 the player wins
        // when the player's sum is 21, the player wins
        // when the dealer's sum is greater than 21 and the player sum is less than 21, the player wins
        if((playerSum > dealerSum && playerSum < 21) || playerSum == 21 || (dealerSum > 21 && playerSum < 21)){
            std::cout << "\nCongratulations, You Win!\n";
        }
        // when the player's sum is less than the dealer's sum
        // or when the player's sum is greater than 21
        // the player loses
        else if(playerSum < dealerSum || playerSum > 21){
            std::cout << "\nOh No, You Lost Bud....\n\n";
        }

        // clears the vectors in case the player wants to play again
        dealerHand.clear();
        playerHand.clear();

        // asks if the player wants to play again
        std::cout << "Play Again? Yes(1) or No(2): ";
        std::cin >> play;

        std::cout << "\n";

    }while(play == 1);

    return 0;
}