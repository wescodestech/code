#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "CardDeck.h"
#include "Card.h"
#include "Players.h"
#include <ctime>
using namespace std;
/**

This is the CardDeck class. This class will contain a working virtual deck of
cards to be used by the players. This class will be able to shuffle, deal and contain the current card 
of the deck to be matched by the players of the game.

@author Wesley Howell
*/

namespace CardGames
{

//Constructor
CardDeck::CardDeck(void)
{
	deck = new vector<Card::Cards>();
	playedDeck = new vector<Card::Cards>();
	for(int i = Card::SPADES_ACE; i <= Card::JOKER2; ++i){
		(*deck).push_back((Card::Cards)i);
	}
	shuffleNewDeck();
	dealCards();
	playGame();
}

//Copy Constructor
CardDeck::CardDeck(const CardDeck & source)
{
	(*deck).clear();
	(*playedDeck).clear();
		for(int i = Card::SPADES_ACE; i <= Card::JOKER2; ++i){
		(*deck).push_back((Card::Cards)i);
	}
	shuffleNewDeck();
	playedDeck = new vector<Card::Cards>();
	dealCards();
}

//Destructor
CardDeck::~CardDeck(void)
{
    if( deck )
    {
        deck->clear();
        delete deck;
    }

    if( playedDeck )
    {
        playedDeck->clear();
        delete playedDeck;
    }

    if( computer )
    {
        delete computer;
    }

    if( person )
    {
        delete person;
    }

	currentCard = "";
}

//Overloaded Equals Operators
CardDeck& CardDeck::operator= (const CardDeck & source)
{
	if (&source == this)
		return *this;

	delete deck;
	deck = source.deck;

	delete playedDeck;
	playedDeck = source.playedDeck;

	currentCard = source.currentCard;
	return *this;
}

//Get Face Up Card
string CardDeck::getFaceUpCard(void) const
{
	return "";
}

//Get the next card from the deck
string CardDeck::getNextCard(void)const
{
	Card::Cards nextCard = (*deck).front();
	string cardStr = Card::toString(nextCard);
	cout << endl << cardStr << endl;
	return cardStr;
}

//Shuffle Deck
void CardDeck::shuffleNewDeck(void)
{
	srand(unsigned (time (NULL)));

	random_shuffle ((*deck).begin(), (*deck).end());
}

//Deal cards
void CardDeck::dealCards(void)
{
	computer = new Players();
	person = new Players();

	//Make the computers hand
	for(vector<Card::Cards>::iterator ndx = (*deck).begin(); ndx<(*deck).begin()+7; ++ndx){
		(*computer).addToHand(*ndx);
	}
	//remove those from the deck
	(*deck).erase((*deck).begin(),(*deck).begin()+7);

	//Make the players hand
	for(vector<Card::Cards>::iterator ndx = (*deck).begin(); ndx<(*deck).begin()+7; ++ndx){
		(*person).addToHand(*ndx);
	}
	//remove from deck
	(*deck).erase((*deck).begin(),(*deck).begin()+7);
}

//Play the game
void CardDeck::playGame()const
{

	//Get First card from the top of the deck and add to the played Deck to start game
	vector<Card::Cards>::iterator deckIt = (*deck).begin();
	Card::Cards startCard = *deckIt;
	(*playedDeck).push_back(startCard);
	(*deck).erase((*deck).begin());
	bool continueGame = true;
	//Begin Game
	//while( (((*person).getHand()).empty()) == false || (((*computer).getHand()).empty()) == false ){
	while(continueGame == true){

		//Display the top card of the deck
		Card::Cards topCard = (*playedDeck).back();
		cout << "The Top Card of the Deck is..." << endl << Card::toString(topCard) <<endl;
		
		//Display player 1's hand on the console
		vector<Card::Cards> p1Hand = (*person).getHand();
		cout << "**** Your Hand Contains ****" << endl;
		int count = 1;
		for(vector<Card::Cards>::iterator ndx = p1Hand.begin(); ndx < p1Hand.end(); ++ndx){
			cout<< count <<". " << Card::toString(*ndx) << endl;
			count++;
		}		
		
		//Ask the user to enter a card or draw from the pile
		cout << "Do you want to play a card or draw from the Pile" << endl
			<< "Enter the number next to the card to play it or press 'Zero' to Draw"<<endl;
		int input;
		cin >> input;

		//If the player needs to draw a card and play it
		if(input == 0){
			vector<Card::Cards>::iterator drawCard = (*deck).begin();
			(*person).addToHand(*drawCard);
			(*deck).erase(drawCard);
			//redisplay cards
			cout<< "##### Your new Hand contains #####" << endl;
			int count = 1;
			p1Hand = (*person).getHand();
			for(vector<Card::Cards>::iterator ndx = p1Hand.begin(); ndx < p1Hand.end(); ++ndx){
				cout<< count <<". " << Card::toString(*ndx) << endl;
				count++;
			}
			//Get input for a card to play
			cout << "Can you play a card?" << endl <<
				"If so enter the number next to the card you want to play" << endl <<
				"Otherwise enter Zero to pass" << endl;
			cin >> input;
			//Validate card and add to deck of played cards
			if(input != 0) {
				vector<Card::Cards>::iterator hand = p1Hand.begin()+(input-1);
				//Card is Valid
				if(Card::compareTo(*hand, (*playedDeck).back())){
					(*playedDeck).push_back(p1Hand[(input-1)]);
					(*person).removeFromHand(input);
				}
			}
		}
		//Player has a card to play
		else {
			vector<Card::Cards>::iterator hand = p1Hand.begin()+(input-1);
				//Card is Valid
				if(Card::compareTo(*hand, (*playedDeck).back())){
					(*playedDeck).push_back(p1Hand[(input-1)]);
					(*person).removeFromHand(input);
				}
		}

		//Now its the computer's Turn
		computerPlay();

		system("CLS");

		if((*person).getHand().size() == 1) cout<< "Player 1 -- UNO!" <<endl;
		if((*computer).getHand().size() == 1) cout<< "Computer -- UNO!" <<endl;

		if((*computer).getHand().size() == 0 || (*person).getHand().size() == 0){
			if((*computer).getHand().size() == 0){
			cout<< "Thanks For Playing" << endl << "Too bad the computer won!" <<endl;
			}else cout << "CONGRATULATIONS!!!!" << endl << "YOU WON!" << endl;
			continueGame = false;
		}
	}
}

void CardDeck::computerPlay(void)const
{

	// Now it is the computer's Turn
	Card::Cards topCard = (*playedDeck).back();
	vector<Card::Cards> p2Hand = (*computer).getHand();
	//Iterate to find a valid card
	int counter = 1;
	for(vector<Card::Cards>::iterator index = p2Hand.begin(); index < p2Hand.end(); ++index){
		if(Card::compareTo(*index, topCard)){
			//If we get here there is a valid card
			(*playedDeck).push_back(*index);
			(*computer).removeFromHand(counter);
			++counter;
			return;
		}
	}
	vector<Card::Cards>::iterator drawCard = (*deck).begin();
	//see if this card can be played
	if(Card::compareTo(*drawCard, topCard)){
		(*playedDeck).push_back(*drawCard);
		(*deck).erase(drawCard);
		return;
	}
	//if Not add it to the hand
	(*computer).addToHand(*drawCard);
	(*deck).erase(drawCard);
	return;
}
}