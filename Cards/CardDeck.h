#ifndef CARD_DECK_HPP
#define CARD_DECK_HPP

#include <string>
#include <vector>
#include "Card.h"
#include "Players.h"

using namespace std;

namespace CardGames
{
/**

This is the header file for the CardDeck class. This class will contain a working virtual deck of
cards to be used by the players. This class will be able to shuffle, deal and contain the current card 
of the deck to be matched by the players of the game.

@author Wesley Howell
*/

class CardDeck{
public:
	//Constructors
	/**
	Default constructor for a deck of cards, this constructor should be the main one used by the
	program
	*/
	CardDeck(void);

	/**
	Copy Constructor for the card deck, this will be used if the deck needs to be reshuffled and/or remade
	*/
	CardDeck(const CardDeck & source);

	/**
	Destructor to return the memory used by the card deck
	*/
	~CardDeck(void);

	/**
	Overload = operator used in order to assign the variables of the deck
	*/
	CardDeck& operator= (const CardDeck & source);

	//Accessors
	/** Return the current face-up card needed to play the game 
	@return String the name of the current face up card*/
	string getFaceUpCard(void) const;

	/** Return the next card in the deck 
	@return String the name of the next card in the deck*/
	string getNextCard(void) const;

	//Mutators
	/** create a new deck to play the game */
	void shuffleNewDeck(void);

	/**Deal the cards to each respective player */
	void dealCards(void);

	/** Plays the game */
	void playGame()const;

	void computerPlay(void)const;

private:
	//pointer to reference a vector of cards
	vector<Card::Cards>* deck;
	vector<Card::Cards>* playedDeck;

	//string values of current cards
	string currentCard;

	//pointers for each of the players in the card game
	Players* computer;
	Players* person;

};
}
#endif
