/*
* Author:       John Meeks
* Purpose:      This header file provides declarations for the "Hand" class
*/

#ifndef HAND_H
#define HAND_H

#include <string>
#include <vector>
#include <ctime>
#include "card.h"

namespace handHeader {

class Hand {
	//declares private data members for Hand class
        private:
                std::vector<cardHeader::Card> cardHand;

	//declares public data members and functions for Hand class
        public:
		//adds a card to the hand
		void add_card(cardHeader::Card newCard) {
			cardHand.push_back(newCard);
		}
	
		//gets the total point value for the hand
		int get_hand_total() const {
			int total = 0, aceCount = 0;
			for(unsigned int i = 0; i < cardHand.size(); i++){
				if(cardHand[i].get_rank() == "Ace"){//if card is an Ace, adds 1 and determines if value should be changed to 11 later
					total += 1;
					aceCount++;
				} else { //if card is not an ace, adds value to total
					total += cardHand[i].get_value();
				}
			}
			
			for(int a = 0; a < aceCount; a++){ //loops through all of the aces in the hand and determines the highest combination less than 21 of point values of either 1 or 10 for each card
				if((total + 10) <= 21){
					total += 10;
				}
			}

			return total;
		}

                //gets string representation of card
                std::string get_player_hand() const {
			std::string handDisplay;
			for(unsigned int i = 0; i < cardHand.size(); i++){
				handDisplay += cardHand[i].get_card() + '\n';
			}

                        return handDisplay;
                }

		//gets the hand of the dealer
                std::string get_dealer_hand() const {
                        std::string handDisplay;
                        for(unsigned int i = 1; i < cardHand.size(); i++){
                                handDisplay += cardHand[i].get_card() + '\n';
                        }

                        return handDisplay;
                }

		//overloads the += operator for the Hand class
		Hand operator+= (const cardHeader::Card& right) {
			cardHand.push_back(right);
			return *this;
		}
	
};
};

#endif
