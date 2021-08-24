/*
* Author:       John Meeks
* Purpose:      This header file provides declarations for the "Card" class
*/

#ifndef CARD_H
#define CARD_H

#include <string>

namespace cardHeader {

	class Card {
		//define data members for Card class
        	private:
                	std::string rank;
                	std::string suit;
			int value;

		//define public data member and functions for Card class
        	public:
			//sets card rank
                	void set_rank(std::string rankIn) {
                        	rank = rankIn;
                	}
			//sets card suit
                	void set_suit(std::string suitIn) {
                        	suit = suitIn;
                	}

			//sets card value
			void set_value(int valueIn) {
				value = valueIn;
			}

			//gets card value
			int get_value() const {
				return value;
			}

                        //gets card value
                        std::string get_rank() const {
                                return rank;
                        }

			//gets string representation of card
                	std::string get_card() const {
                        	return rank + " of " + suit;
                	}
		
			//overloads << oeprator
			friend std::ostream& operator<< (std::ostream& out, const Card& thisCard) {
				out << thisCard.get_card();;
				return out;
			}

	};


};

#endif
