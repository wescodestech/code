#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include <string>
#include <vector>
#include "Card.h"
#include "Chips.h"

using namespace std;

namespace CardGames
{
    
/** 
 
This class will handle the players hands and commands from the players. 
This will contain a vector of cards for each player to play.

@author Wesley Howell
*/

class Players
{

public:
	//Constructors
	/**Constructor to create a hand for the player to play with*/
	Players(void);
	/**Copy constructor*/
	Players(const Players& source);

	//Destructor
	/**Destructor to return memory to heap used by the card hands*/
	~Players(void);

	//Overloaded Equals
	/** overloaded equals operator to allow use of setting players hands equal to each other*/
	Players& operator= (const Players& source);

	//Accessors
	/**Access the players current hand to play
	@return vector<Card::Cards> the vector representing the players hand of cards
	*/
	vector<Card::Cards>& getHand(void);

    /**
     Return the player's set of chips
    */
    Chips& getChips();

	//Mutator
	/** Add a card drawn from the deck to the players hand
	@param card the card to add to the hand
	*/
	void addToHand(Card::Cards card);

	/** Removes the indicated card from the hand 
	@param i the index position of the item to remove
	*/
	void removeFromHand(int i);

private:
	//The vector used to hold the players cards
	vector<Card::Cards>* hand;
    Chips m_chips;

};
}//end CardGames

#endif