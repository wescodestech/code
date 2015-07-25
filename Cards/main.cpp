//
//  main.cpp
//  Cards
//
//  Created by Wesley Howell on 6/26/15.
//  Copyright (c) 2015 Wesley Howell. All rights reserved.
//

#include "CardDeck.h"
#include "Blackjack.h"
#include <iostream>
using namespace std;

/** Driver Programs */
int main (int argc, char* argv[])
{
    cout << "Pick a game: " << endl << "1: Blackjack" << endl << "2: Uno" << endl;

    int input = 0;
    cin >> input;

    switch( input )
    {
        case 1:
        {
            CardGames::Blackjack blackjack;
            blackjack.PlayBlackjack();
        } break;
        case 2:
        {
            //Create a new instance of the game
            CardGames::CardDeck* playUno;
            playUno = new CardGames::CardDeck();

            //delete all memory used by the game
            delete playUno;
        } break;
        default:
            cout << "Please choose a valid game." << endl;
    }

    
    //exit program
    return 0;
}
