//
//  Blackjack.h
//  Cards
//
//  Created by Wesley Howell on 6/27/15.
//  Copyright (c) 2015 Wesley Howell. All rights reserved.
//

#ifndef Cards_Blackjack_h
#define Cards_Blackjack_h

#include "Card.h"
#include "Chips.h"
#include "Players.h"

namespace CardGames
{

class  Blackjack
{

    enum Outcome
    {
        OUTCOME_WINNER
        , OUTCOME_LOSS
        , OUTCOME_PUSH
    };

    enum Move
    {
        STAY
        , HIT
        , DOUBLE_DOWN
        , SPLIT
    };
// For this game we will need
// Choosed number of Decks of cards (x6)
// A player
// A dealer
// Money
// Get Card Total Function
//   Determine total vs bust
//   Compare to dealer?

// Game Play
    // Shuffle
    // Deal

    // Players move
    // Hit
    // Split ( Paired up cards only )
    // Double Down ( Double Down for less )

    // Dealers turn
    // Dealer turns card ( Draws to 17, hits on 'soft' 17 )

    // Clean up/Cards removed from hand and discarded
public:
    Blackjack();
    ~Blackjack();

    void CreateCardDeck();
    void ClearCardDeck();
    void ShuffleCardDeck();

    unsigned int
    GetCardTotal( const vector<Card::Cards>& a_hand );

    bool DealCards();
    void CleanupDealtCards();

    void PlaceBet( const unsigned int a_amount );

    bool MakePlayerMove( Move a_action );

    void TurnDealerCards();

    Outcome EvaluateWinner(); // Players dealer, Players user1

    void PlayBlackjack();

private:
    vector<CardGames::Card::Cards> m_deck;
    Players m_player;
    Players m_dealer;
};

}
#endif
