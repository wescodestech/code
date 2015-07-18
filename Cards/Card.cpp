#include <string>
#include <vector>
#include "CardDeck.h"
#include "Card.h"
#include "Players.h"
using namespace std;

namespace CardGames
{
//Default Constructor
Card::Card(void)
{
	myCard = SPADES_ACE;
	cardString = "Ace of Spades";
	cardIntValue = 0;
}

//Constructor
Card::Card(Card::Cards card)
{
	myCard = card;
	cardString = toString(card);
	cardIntValue = getIntValue(card);
}

//Copy Constructor
Card::Card(const Card & source)
{
	myCard = source.myCard;
	cardString = toString(source.myCard);
	cardIntValue = getIntValue(source.myCard);
}

//Destructor
Card::~Card(void)
{
	myCard = SPADES_ACE;
	cardString = "";
	cardIntValue = 0;
}

//Overloaded Operators
Card& Card::operator= (const Card & source)
{

	if (&source == this)
		return *this;

	myCard = source.myCard;
	cardString = source.cardString;
	cardIntValue = source.cardIntValue;
	return *this;
}

Card& Card::operator= (const Cards source)
{
	myCard = source;
	cardString = toString(source);
	cardIntValue = getIntValue(source);
	return *this;
}

//Accessors
string Card::toString(Cards card)
{
	//find and return the string value of a card
	switch(card){
	case SPADES_ACE:   return "Ace of Spades";
	case SPADES_2:     return "2 of Spades";
	case SPADES_3:     return "3 of Spades";
	case SPADES_4:     return "4 of Spades";
	case SPADES_5:     return "5 of Spades";
	case SPADES_6:     return "6 of Spades";
	case SPADES_7:     return "7 of Spades";
	case SPADES_8:     return "8 of Spades";
	case SPADES_9:     return "9 of Spades";
	case SPADES_10:    return "10 of Spades";
	case SPADES_JACK:  return "Jack of Spades";
	case SPADES_QUEEN: return "Queen of Spades";
	case SPADES_KING:  return "King of Spades";
	case HEARTS_ACE:   return "Ace of HEARTS";
	case HEARTS_2:     return "2 of HEARTS";
	case HEARTS_3:     return "3 of HEARTS";
	case HEARTS_4:     return "4 of HEARTS";
	case HEARTS_5:     return "5 of HEARTS";
	case HEARTS_6:     return "6 of HEARTS";
	case HEARTS_7:     return "7 of HEARTS";
	case HEARTS_8:     return "8 of HEARTS";
	case HEARTS_9:     return "9 of HEARTS";
	case HEARTS_10:    return "10 of HEARTS";
	case HEARTS_JACK:  return "Jack of HEARTS";
	case HEARTS_QUEEN: return "Queen of HEARTS";
	case HEARTS_KING:  return "King of HEARTS";
	case CLUBS_ACE:    return "Ace of CLUBS";
	case CLUBS_2:      return "2 of CLUBS";
	case CLUBS_3:      return "3 of CLUBS";
	case CLUBS_4:      return "4 of CLUBS";
	case CLUBS_5:      return "5 of CLUBS";
	case CLUBS_6:      return "6 of CLUBS";
	case CLUBS_7:      return "7 of CLUBS";
	case CLUBS_8:      return "8 of CLUBS";
	case CLUBS_9:      return "9 of CLUBS";
	case CLUBS_10:     return "10 of CLUBS";
	case CLUBS_JACK:   return "Jack of CLUBS";
	case CLUBS_QUEEN:  return "Queen of CLUBS";
	case CLUBS_KING:   return "King of CLUBS";
	case DIAMONDS_ACE: return "Ace of DIAMONDS";
	case DIAMONDS_2:   return "2 of DIAMONDS";
	case DIAMONDS_3:   return "3 of DIAMONDS";
	case DIAMONDS_4:   return "4 of DIAMONDS";
	case DIAMONDS_5:   return "5 of DIAMONDS";
	case DIAMONDS_6:   return "6 of DIAMONDS";
	case DIAMONDS_7:   return "7 of DIAMONDS";
	case DIAMONDS_8:   return "8 of DIAMONDS";
	case DIAMONDS_9:   return "9 of DIAMONDS";
	case DIAMONDS_10:  return "10 of DIAMONDS";
	case DIAMONDS_JACK:  return "Jack of DIAMONDS";
	case DIAMONDS_QUEEN: return "Queen of DIAMONDS";
	case DIAMONDS_KING:  return "King of DIAMONDS";
	case JOKER1:         return "Joker";
	case JOKER2:         return "Joker";
	}
	return "Error Not a Correct Card";
}

int Card::getIntValue(Cards card)
{
	//Return the integer value of each card 
	switch(card){
	case SPADES_ACE: return 0;
	case SPADES_2: return 1;
	case SPADES_3: return 2;
	case SPADES_4: return 3;
	case SPADES_5: return 4;
	case SPADES_6: return 5;
	case SPADES_7: return 6;
	case SPADES_8: return 7;
	case SPADES_9: return 8;
	case SPADES_10: return 9;
	case SPADES_JACK: return 10;
	case SPADES_QUEEN: return 11;
	case SPADES_KING: return 12;
	case HEARTS_ACE: return 13;
	case HEARTS_2: return 14;
	case HEARTS_3: return 15;
	case HEARTS_4: return 16;
	case HEARTS_5: return 17;
	case HEARTS_6: return 18;
	case HEARTS_7: return 19;
	case HEARTS_8: return 20;
	case HEARTS_9: return 21;
	case HEARTS_10: return 22;
	case HEARTS_JACK: return 23;
	case HEARTS_QUEEN: return 24;
	case HEARTS_KING: return 25;
	case CLUBS_ACE: return 26;
	case CLUBS_2: return 27;
	case CLUBS_3: return 28;
	case CLUBS_4: return 29;
	case CLUBS_5: return 30;
	case CLUBS_6: return 31;
	case CLUBS_7: return 32;
	case CLUBS_8: return 33;
	case CLUBS_9: return 34;
	case CLUBS_10: return 35;
	case CLUBS_JACK: return 36;
	case CLUBS_QUEEN: return 37;
	case CLUBS_KING: return 38;
	case DIAMONDS_ACE: return 39;
	case DIAMONDS_2: return 40;
	case DIAMONDS_3: return 41;
	case DIAMONDS_4: return 42;
	case DIAMONDS_5: return 43;
	case DIAMONDS_6: return 44;
	case DIAMONDS_7: return 45;
	case DIAMONDS_8: return 46;
	case DIAMONDS_9: return 47;
	case DIAMONDS_10: return 48;
	case DIAMONDS_JACK: return 49;
	case DIAMONDS_QUEEN: return 50;
	case DIAMONDS_KING: return 51;
	case JOKER1: return 52;
	case JOKER2: return 53;
	}
	//Not a valid card
	return 54;
}

Card::Cards Card::fromInt(int card)
{
	switch(card){
	case 0: return SPADES_ACE;
	case 1: return SPADES_2;
	case 2: return SPADES_3;
	case 3:return SPADES_4;
	case 4: return SPADES_5;
	case 5: return SPADES_6;
	case 6: return SPADES_7;
	case 7: return SPADES_8;
	case 8: return SPADES_9;
	case 9: return SPADES_10;
	case 10: return SPADES_JACK;
	case 11: return SPADES_QUEEN;
	case 12: return SPADES_KING;
	case 13: return HEARTS_ACE;
	case 14: return HEARTS_2;
	case 15: return HEARTS_3;
	case 16: return HEARTS_4;
	case 17: return HEARTS_5;
	case 18: return HEARTS_6;
	case 19: return HEARTS_7;
	case 20: return HEARTS_8;
	case 21: return HEARTS_9;
	case 22: return HEARTS_10;
	case 23: return HEARTS_JACK;
	case 24: return HEARTS_QUEEN;
	case 25: return HEARTS_KING;
	case 26: return CLUBS_ACE;
	case 27: return CLUBS_2;
	case 28: return CLUBS_3;
	case 29: return CLUBS_4;
	case 30: return CLUBS_5;
	case 31: return CLUBS_6;
	case 32: return CLUBS_7;
	case 33: return CLUBS_8;
	case 34: return CLUBS_9;
	case 35: return CLUBS_10;
	case 36: return CLUBS_JACK;
	case 37: return CLUBS_QUEEN;
	case 38: return CLUBS_KING;
	case 39: return DIAMONDS_ACE;
	case 40: return DIAMONDS_2;
	case 41: return DIAMONDS_3;
	case 42: return DIAMONDS_4;
	case 43: return DIAMONDS_5;
	case 44: return DIAMONDS_6;
	case 45: return DIAMONDS_7;
	case 46: return DIAMONDS_8;
	case 47: return DIAMONDS_9;
	case 48: return DIAMONDS_10;
	case 49: return DIAMONDS_JACK;
	case 50: return DIAMONDS_QUEEN;
	case 51: return DIAMONDS_KING;
	case 52: return JOKER1;
	case 53: return JOKER2;
	}
	return JOKER2;
}

bool Card::compareTo(Card::Cards cardPlay, Card::Cards cardUp)
{
	
	//Convert to int values
	int cardPlayInt = getIntValue(cardPlay);
	int cardUpInt = getIntValue(cardUp);

	//if card is a Joker it is valid
	if(cardPlayInt == 52 || cardPlayInt == 53
		|| cardUpInt == 52 || cardUpInt == 53) return true;

	//if the cards are the same value
	if(cardPlayInt == cardUpInt + 13 || cardPlayInt == cardUpInt + 26 || cardPlayInt == cardUpInt + 39||
		cardPlayInt == cardUpInt - 13|| cardPlayInt == cardUpInt - 26|| cardPlayInt == cardUpInt - 39) 
		return true;

	//If the cards are spades
	if(cardPlayInt >= 0 && cardPlayInt <=12 && cardUpInt>=0 && cardUpInt<=12) return true;
	
	//If the cards are hearts
	if(cardPlayInt >= 13 && cardPlayInt <=25 && cardUpInt>=13 && cardUpInt<=25) return true;

	//If the cards are clubs
	if(cardPlayInt >= 26 && cardPlayInt <=38 && cardUpInt>=26 && cardUpInt<=38) return true;

	//If the cards are diamonds
	if(cardPlayInt >= 39 && cardPlayInt <=51 && cardUpInt>=39 && cardUpInt<=51) return true;

	//IF we make it here the cards are not valid
	return false;
}
    
}
