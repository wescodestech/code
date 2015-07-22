//
//  Blackjack.cpp
//  Cards
//
//  Created by Wesley Howell on 6/27/15.
//  Copyright (c) 2015 Wesley Howell. All rights reserved.
//

// Card Game includes
#include "Blackjack.h"
#include "Chips.h"
#include "Players.h"

// STL Includes
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;

namespace CardGames
{
    Blackjack::Blackjack()
        : m_dealer( Players() )
        , m_player( Players() )
        , m_deck()
    {
    }

    Blackjack::~Blackjack()
    {
        m_deck.clear();
    }

    void
    Blackjack::CreateCardDeck()
    {
        // Make a deck for blackjack
        // TODO: This is for 6-deck blackjack. Modify to be configurable up to 6.
        for( unsigned int c = 0; c <= 6; ++c )
        {
            for( unsigned int card = Card::SPADES_ACE; card < Card::JOKER1; ++card )
            {
                m_deck.push_back( static_cast<Card::Cards>( card ) );
            }
        }
    }

    void
    Blackjack::ShuffleCardDeck()
    {
        // Shuffle the deck of cards if it's been populated.
        if( m_deck.size() > 0 )
        {
            srand( unsigned ( time( NULL) ) );
            random_shuffle( m_deck.begin(), m_deck.end() );

            // Burn card
            m_deck.erase( m_deck.begin() );
        }
    }

    unsigned int
    Blackjack::GetCardTotal
        (
        const vector<Card::Cards>& a_hand
        )
    {
        unsigned int faceCardTotal = 0;
        unsigned int numberOfAces = 0;

        for( vector<Card::Cards>::const_iterator card = a_hand.begin(); card < a_hand.end(); ++card )
        {
            switch(*card)
            {
                case Card::SPADES_ACE:
                    ++numberOfAces;
                case Card::SPADES_2:
                    faceCardTotal += 2;
                case Card::SPADES_3:
                    faceCardTotal += 3;
                case Card::SPADES_4:
                    faceCardTotal += 4;
                case Card::SPADES_5:
                    faceCardTotal += 5;
                case Card::SPADES_6:
                    faceCardTotal += 6;
                case Card::SPADES_7:
                    faceCardTotal += 7;
                case Card::SPADES_8:
                    faceCardTotal += 8;
                case Card::SPADES_9:
                    faceCardTotal += 9;
                case Card::SPADES_10:
                    faceCardTotal += 10;
                case Card::SPADES_JACK:
                    faceCardTotal += 10;
                case Card::SPADES_QUEEN:
                    faceCardTotal += 10;
                case Card::SPADES_KING:
                    faceCardTotal += 10;
                case Card::HEARTS_ACE:
                    ++numberOfAces;
                case Card::HEARTS_2:
                    faceCardTotal += 2;
                case Card::HEARTS_3:
                    faceCardTotal += 3;
                case Card::HEARTS_4:
                    faceCardTotal += 4;
                case Card::HEARTS_5:
                    faceCardTotal += 5;
                case Card::HEARTS_6:
                    faceCardTotal += 6;
                case Card::HEARTS_7:
                    faceCardTotal += 7;
                case Card::HEARTS_8:
                    faceCardTotal += 8;
                case Card::HEARTS_9:
                    faceCardTotal += 9;
                case Card::HEARTS_10:
                    faceCardTotal += 10;
                case Card::HEARTS_JACK:
                    faceCardTotal += 10;
                case Card::HEARTS_QUEEN:
                    faceCardTotal += 10;
                case Card::HEARTS_KING:
                    faceCardTotal += 10;
                case Card::CLUBS_ACE:
                    ++numberOfAces;
                case Card::CLUBS_2:
                    faceCardTotal += 2;
                case Card::CLUBS_3:
                    faceCardTotal += 3;
                case Card::CLUBS_4:
                    faceCardTotal += 4;
                case Card::CLUBS_5:
                    faceCardTotal += 5;
                case Card::CLUBS_6:
                    faceCardTotal += 6;
                case Card::CLUBS_7:
                    faceCardTotal += 7;
                case Card::CLUBS_8:
                    faceCardTotal += 8;
                case Card::CLUBS_9:
                    faceCardTotal += 9;
                case Card::CLUBS_10:
                    faceCardTotal += 10;
                case Card::CLUBS_JACK:
                    faceCardTotal += 10;
                case Card::CLUBS_QUEEN:
                    faceCardTotal += 10;
                case Card::CLUBS_KING:
                    faceCardTotal += 10;
                case Card::DIAMONDS_ACE:
                    ++numberOfAces;
                case Card::DIAMONDS_2:
                    faceCardTotal += 2;
                case Card::DIAMONDS_3:
                    faceCardTotal += 3;
                case Card::DIAMONDS_4:
                    faceCardTotal += 4;
                case Card::DIAMONDS_5:
                    faceCardTotal += 5;
                case Card::DIAMONDS_6:
                    faceCardTotal += 6;
                case Card::DIAMONDS_7:
                    faceCardTotal += 7;
                case Card::DIAMONDS_8:
                    faceCardTotal += 8;
                case Card::DIAMONDS_9:
                    faceCardTotal += 9;
                case Card::DIAMONDS_10:
                    faceCardTotal += 10;
                case Card::DIAMONDS_JACK:
                    faceCardTotal += 10;
                case Card::DIAMONDS_QUEEN:
                    faceCardTotal += 10;
                case Card::DIAMONDS_KING:
                    faceCardTotal += 10;
                default: ;// Do Nothing
            }
        }

        unsigned int total = 0;
        unsigned int aces11 = numberOfAces + 10;

        // Note, one of the Aces can be 1 or 11.
        // return the highest possible number.
        if( (faceCardTotal + numberOfAces) > 11 )
        {
            total = faceCardTotal + numberOfAces;
        }
        else
        {
            total = faceCardTotal + aces11;
        }

        return total;
    }

    void
    Blackjack::DealCards()
    {
        vector<Card::Cards>::iterator start = m_deck.begin();
        vector<Card::Cards>::iterator card = m_deck.begin();
        // Add one card to player's hand
        m_player.addToHand( *card );
        ++card;

        // Add face-up card to dealer's hand
        m_dealer.addToHand( *card );
        ++card;

        // Add final card to player's hand
        m_player.addToHand( *card );
        ++card;

        // Add final card to dealer's hand
        m_dealer.addToHand( *card );

        // Remove cards from hand
        m_deck.erase( start, card );
    }

    void
    Blackjack::CleanupDealtCards()
    {
        m_player.getHand().clear();
        m_dealer.getHand().clear();
    }

    void
    Blackjack::PlaceBet( const unsigned int a_amount )
    {
        m_player.getChips().Debit( a_amount );
    }

    void
    Blackjack::MakePlayerMove()
    {
	// Hit
	// Stay
	// Double Down
	// Split (if two of the same cards)
    }

    void
    Blackjack::TurnDealerCards()
    {

    }

    Blackjack::Outcome
    Blackjack::EvaluateWinner()
    {
        Blackjack::Outcome result = Blackjack::OUTCOME_PUSH;
        vector<Card::Cards> player = m_player.getHand();
        vector<Card::Cards> dealer = m_dealer.getHand();

        if( GetCardTotal( player ) > 21 || // Player bust
            GetCardTotal( dealer ) > GetCardTotal( player ) // Dealer hand wins
          )
        {
            // Loss
            result = Blackjack::OUTCOME_LOSS;
        }
        else if ( GetCardTotal( dealer ) == 21 && dealer.size() == 2 ) // Dealer Blackjack
        {
            if( GetCardTotal( player ) > 21 && player.size() == 2 )
            {
                result = Blackjack::OUTCOME_PUSH;
            }
            else
            {
                result = Blackjack::OUTCOME_LOSS;
            }
        }
        else if( GetCardTotal( dealer ) == GetCardTotal( player ) )
        {
            // Push
            result = Blackjack::OUTCOME_PUSH;
        }
        else if( GetCardTotal( dealer ) > 21 )
        {
            // Dealer bust, Winner
            result = Blackjack::OUTCOME_WINNER;
        }
        else
        {
            // Winner
            result = Blackjack::OUTCOME_WINNER;
        }

        return result;
    }

    void Blackjack::PlayBlackjack()
    {
        // Shuffle Cards
        CreateCardDeck();
        vector<Card::Cards>::iterator it = m_deck.begin();

        // Give the player some money to start
        Chips chips = m_player.getChips();
        chips.Credit( 500 );

        bool continueGame = true;
        while( continueGame )
        {
            // Ask a player to place a bet

            // Deal cards to dealer and player

            // Ask player to perform an action

            // See any moves are availible based on action
            // repeat until complete

            // Turn dealer cards

            // Evaluate winner
        }
    }
}
