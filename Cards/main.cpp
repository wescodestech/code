//
//  main.cpp
//  Cards
//
//  Created by Wesley Howell on 6/26/15.
//  Copyright (c) 2015 Wesley Howell. All rights reserved.
//

#include "CardDeck.h"

/** Driver Programs */
int main (int argc, char* argv[])
{
    //Create a new instance of the game
    CardGames::CardDeck* playUno;
    playUno = new CardGames::CardDeck();
    
    //delete all memory used by the game
    delete playUno;
    
    //exit program
    return 0;
}
