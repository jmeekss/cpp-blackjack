/*
* Author:	John Meeks
* Purpose:	This header file provides declarations for the "Deck" class
*/

#ifndef DECK_H
#define DECK_H

#include <string>
#include <vector>
#include <ctime>
#include "card.h"

namespace deckHeader {

class Deck {
	//defines private data members for Deck class
        private:
                std::vector<cardHeader::Card> cardDeck;

	//defines public data members and functions for Deck class
        public:
		//shuffles the card deck
                void shuffle_deck() {
			std::srand(std::time(0));
			std::vector<cardHeader::Card> copyDeck (52);
			std::copy(cardDeck.begin(), cardDeck.begin()+52, copyDeck.begin());
			std::vector<cardHeader::Card> shuffleDeck;
			for(int i = 0; i < 52; i++){
				int r = rand() % (52-i);
				shuffleDeck.push_back(copyDeck[r]);
				copyDeck.erase(copyDeck.begin() + r);
			}
			std::copy(shuffleDeck.begin(), shuffleDeck.begin()+52, cardDeck.begin());			
                }

		//gets the number of cards still in the deck
                int get_card_count() const {
                        return cardDeck.size();
                }

		//gets a card from the deck
                cardHeader::Card get_card_deal() {
			cardHeader::Card deal = cardDeck[cardDeck.size()-1];
                        cardDeck.pop_back();
                        return deal;
                }

		//gets a fresh, unshuffled deck
                void new_deck() {
			cardDeck.clear();

                        std::string rank, suit;
			//adds cards to new deck
                        for(int s = 0; s < 4; s++){
                                switch(s) { //sets suit of new card
                                        case 0:
                                                suit = "Clubs";
                                                break;
                                        case 1:
                                                suit = "Diamonds";
                                                break;
                                        case 2:
                                                suit = "Hearts";
                                                break;
                                        case 3:
                                                suit = "Spades";
                                                break;
                                        default:
                                                suit = "Unknown";
                                }


                                for(int r = 1; r < 14; r++){
                                        cardHeader::Card newCard;
                                        switch(r) { //sets rank of new card, and adds it to the deck
                                                case 1:
                                                        newCard.set_suit(suit);
                                                        newCard.set_rank("Ace");
							newCard.set_value(1);
                                                        cardDeck.push_back(newCard);
                                                        break;
                                                case 2:
                                                        newCard.set_suit(suit);
                                                        newCard.set_rank("2");
                                                        newCard.set_value(2);
                                                        cardDeck.push_back(newCard);
                                                        break;
                                                case 3:
                                                        newCard.set_suit(suit);
                                                        newCard.set_rank("3");
                                                        newCard.set_value(3);
                                                        cardDeck.push_back(newCard);
                                                        break;
                                                case 4:
                                                        newCard.set_suit(suit);
                                                        newCard.set_rank("4");
                                                        newCard.set_value(4);
                                                        cardDeck.push_back(newCard);
                                                        break;
                                                case 5:
                                                        newCard.set_suit(suit);
                                                        newCard.set_rank("5");
                                                        newCard.set_value(5);
                                                        cardDeck.push_back(newCard);
                                                        break;
                                                case 6:
                                                        newCard.set_suit(suit);
                                                        newCard.set_rank("6");
                                                        newCard.set_value(6);
                                                        cardDeck.push_back(newCard);
                                                        break;
                                                case 7:
                                                        newCard.set_suit(suit);
                                                        newCard.set_rank("7");
                                                        newCard.set_value(7);
                                                        cardDeck.push_back(newCard);
                                                        break;
                                                case 8:
                                                        newCard.set_suit(suit);
                                                        newCard.set_rank("8");
                                                        newCard.set_value(8);
                                                        cardDeck.push_back(newCard);
                                                        break;
                                                case 9:
                                                        newCard.set_suit(suit);
                                                        newCard.set_rank("9");
                                                        newCard.set_value(9);
                                                        cardDeck.push_back(newCard);
                                                        break;
                                                case 10:
                                                        newCard.set_suit(suit);
                                                        newCard.set_rank("10");
                                                        newCard.set_value(10);
                                                        cardDeck.push_back(newCard);
                                                        break;
                                                case 11:
                                                        newCard.set_suit(suit);
                                                        newCard.set_rank("Jack");
                                                        newCard.set_value(10);
                                                        cardDeck.push_back(newCard);
                                                        break;
                                                case 12:
                                                        newCard.set_suit(suit);
                                                        newCard.set_rank("Queen");
                                                        newCard.set_value(10);
                                                        cardDeck.push_back(newCard);
                                                        break;
                                                case 13:
                                                        newCard.set_suit(suit);
                                                        newCard.set_rank("King");
                                                        newCard.set_value(10);
                                                        cardDeck.push_back(newCard);
                                                        break;
                                                default:
                                                        newCard.set_suit("Unknown");
                                                        newCard.set_rank("Unknown");
                                                        newCard.set_value(0);
                                                        cardDeck.push_back(newCard);
                                        }
                                }


                        }

                }
};

};

#endif
