#include<string>
#include<vector>
#include "CardDeck.h"
#include "Card.h"
#include "Players.h"
using namespace std;

namespace CardGames
{
    
/** 

This class will handle the players hands and commands from the players. 
This will contain a vector of cards for each player to play.

@author Wesley Howell
*/

//Constructors
Players::Players(void)
    : m_chips()
{
	//Create a new hand for the player
	hand = new vector<Card::Cards>();
}
//Copy Constructor
Players::Players(const Players& source)
{

	(*hand).clear();
	hand = source.hand;
    m_chips = source.m_chips;

}

//Destructor
Players::~Players(void)
{

	if( hand )
    {
        hand->clear();
        delete hand;
    }
}

//Overload Operators
Players& Players::operator=(const Players& source)
{
	if(&source == this)
		return *this;

    if( hand )
    {
        delete hand;
    }
    hand = source.hand;

    m_chips = source.m_chips;

	return *this;
}

//Accessors
vector<Card::Cards>& Players::getHand(void)
{
	return *hand;
}

Chips& Players::getChips()
{
    return m_chips;
}

//Mutator
void Players::addToHand(Card::Cards card)
{
	(*hand).push_back(card);
}

void Players::removeFromHand(int i)
{
	(*hand).erase((*hand).begin() + (i-1));
}
    
}