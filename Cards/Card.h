#ifndef CARD_HPP
#define CARD_HPP

#include <vector>
#include <string>
using namespace std;

namespace CardGames
{
class Card{

public:

	//Enum Values
	/**Enumerated Data Type Cards
	Each card in a standard deck, including jokers
	Note:Values 0-12 are Spades, 13-25 are Hearts, 26-38 are Clubs, 39-51 are Diamonds, 52 and 53 are Jokers
	*/
	enum Cards {SPADES_ACE, SPADES_2, SPADES_3, SPADES_4, SPADES_5, SPADES_6, SPADES_7, SPADES_8, SPADES_9, SPADES_10, SPADES_JACK, SPADES_QUEEN, SPADES_KING, 
			HEARTS_ACE, HEARTS_2, HEARTS_3, HEARTS_4, HEARTS_5, HEARTS_6, HEARTS_7, HEARTS_8, HEARTS_9, HEARTS_10, HEARTS_JACK, HEARTS_QUEEN, HEARTS_KING,
			CLUBS_ACE, CLUBS_2, CLUBS_3, CLUBS_4, CLUBS_5, CLUBS_6, CLUBS_7, CLUBS_8, CLUBS_9, CLUBS_10, CLUBS_JACK, CLUBS_QUEEN, CLUBS_KING,
			DIAMONDS_ACE, DIAMONDS_2, DIAMONDS_3, DIAMONDS_4, DIAMONDS_5, DIAMONDS_6, DIAMONDS_7, DIAMONDS_8, DIAMONDS_9, DIAMONDS_10, DIAMONDS_JACK, DIAMONDS_QUEEN, DIAMONDS_KING,
			JOKER1, JOKER2};

	//Constructors
	/** Defauld Card constructor */
	Card(void);
	/** Card Constructor */
	Card(Cards card);
	/** Card Copy Constructor */
	Card(const Card & source);

	//Destructor
	/** Destructor for the cards */
	~Card(void);

	//Overload Equals Assignment Operators
	/** Overloaded Assignment operator for a card object */
	Card& operator= (const Card & source);
	/** Overloaded Assignment operator for a cards type */
	Card& operator= (const Cards source);

	//Accessors
	/** Accessor for getting the string value of the card
	@param card the card value that you want to get the string value of
	@return string the cards string value
	*/
	static string toString(Cards card);

	/*Return  the int value of the card based on its Enum postition
	@param card the card you want to get the interger value of
	@return in the cards int value
	*/
	static int getIntValue(Cards card);

	/**
	returns the card value from an integer value passed
	@param int card the int value to represent a card
	@return Card the card value of the int
	*/
	static Cards fromInt(int card);

	/**
	Finds out whether or not a card is valid for playing in the game
	@param card1 the first card to compare
	@param card2 the second card to compare
	@return bool true if the card can be played
	*/
	static bool compareTo(Cards cardPlay, Cards cardUp);

private:
	//Data variables
	Cards myCard;
	string cardString;
	int cardIntValue;
};
}

#endif