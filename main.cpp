/*
* Author:	John Meeks
* Purpose:	This program asks the user how many cards they want from a shuffled deck
*		and then deals them that many cards, displays them, and displays how many
*		cards are left in the deck
*/

#include <string>
#include <limits>
#include <iostream>
#include "deck.h"
#include "card.h"
#include "hand.h"

using namespace std;

char askReplay();
char askType();

int main() {
	//displays intro message
	cout << "Blackjack\n";

	do {
	        //create a member of the "Deck" class
        	deckHeader::Deck cardDeck;

        	//fills the deck with cards, and then shuffles them
        	cardDeck.new_deck();
        	cardDeck.shuffle_deck();

		//creates hands for player and dealer
		handHeader::Hand dealer;
		handHeader::Hand player;

		//variable for if player's hand gets Blackjack (21 points on start)
		bool blackjack = 0;

		//deals 2 cards to each player and dealer
		dealer += cardDeck.get_card_deal();
                dealer += cardDeck.get_card_deal();
		player += cardDeck.get_card_deal();
		player += cardDeck.get_card_deal();

		//displays dealer's show card and players deck
		cout << "\nDEALER'S SHOW CARD:\n" << dealer.get_dealer_hand();		
		cout << "\nYOUR CARDS:\n" << player.get_player_hand();
		
		//determiens if player has blackjack
		if(player.get_hand_total() == 21){
			blackjack = 1;
		}

		//if player does not have blackjack, asks if player wants to hit or stand until their points exceed 21, or they stand
		if(!blackjack){
			while(askType() == 'h' && cardDeck.get_card_count() > 0){
		
				player += cardDeck.get_card_deal();
	                	cout << "\nYOUR CARDS:\n" << player.get_player_hand();

                		if(player.get_hand_total() > 20 && player.get_hand_total() > 20){
                        		break;
                		}
			}
		}

		//dealer draws card until their total is higher than 17
		while(dealer.get_hand_total() < 17){
			dealer += cardDeck.get_card_deal();
		}

		//displays dealer and player cards
                cout << "DEALER'S CARDS:\n" << dealer.get_player_hand();
                cout << "\nYOUR CARDS:\n" << player.get_player_hand();

		//display dealer and player points
		cout << "\nYOUR POINTS:" << player.get_hand_total()
			<< "\nDEALER'S POINTS:" << dealer.get_hand_total() << endl;

		//determines win/loss type, and displays it to player
		if(blackjack){ //player gets blackjack(21 on initial deal)
			cout << "\nBLACKJACK! You win!";
		} else if(player.get_hand_total() > 21){ //player busts
                        cout << "\nYou busted! You lose.";
		} else if(dealer.get_hand_total() > 21){ //dealer busts
                        cout << "\nThe dealer busted! You win!";
		} else if(player.get_hand_total() > dealer.get_hand_total()){//player wins
                        cout << "\nYour total is higher, you win!";
		} else if(player.get_hand_total() < dealer.get_hand_total()){ //dealer wins
                        cout << "\nThe dealer's total is higher, you lose.";
		} else { //push, no one wins
                        cout << "\nPush! No one wins.";
		}
	} while(askReplay() == 'y');

	//returns 0 to indicate normal program exit
	return 0;
}

//asks the user if they want to play again
char askReplay(){
        //variables for valid selection and choice user enters
        int validSelection = 0;
        char choice;

        //loops until user enters valid choice
        while(validSelection == 0){
                        //ask user for choice, and clears buffer after they enter it
                        cout << "\n\nPlay again? (y/n): ";
                        cin >> choice;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        //Tells user if their choice is invalid
                        if(tolower(choice) != 'y' && tolower(choice) != 'n'){
                                cout << "Invalid selection\n\n";
                        } else {
                                return tolower(choice);
                        }
                }

        return 'n';
}

//asks the user if they want to enter customer or employee data
char askType(){
        //variables for valid selection and choice user enters
        int validSelection = 0;
        char choice;

        //loops until user enters valid choice
        while(validSelection == 0){
                        //ask user for choice, and clears buffer after they enter it
                        cout << "\nHit or Stand? (h/s): ";
                        cin >> choice;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        //Tells user if their choice is invalid
                        if(tolower(choice) != 's' && tolower(choice) != 'h'){
                                cout << "Invalid selection\n\n";
                        } else {
                                return tolower(choice);
                        }
                }

        return 'n';
}
