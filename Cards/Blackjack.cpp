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
    : m_deck()
    {
    }

    Blackjack::~Blackjack()
    {
        m_deck.clear();
    }

    void
    Blackjack::CreateCardDeck()
    {
        if( m_deck.size() > 0 )
        {
            m_deck.clear();
        }

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
    Blackjack::ClearCardDeck()
    {
        m_deck.clear();
    }

    // Random number generator for use in ShuffleCardDeck
    int RNG (int n)
    {
        return std::rand() / (1.0 + RAND_MAX) * n;
    }

    void
    Blackjack::ShuffleCardDeck()
    {
        // Shuffle the deck of cards if it's been populated.
        if( m_deck.size() > 0 )
        {


            srand( unsigned( time(NULL) ) );
            random_shuffle( m_deck.begin(), m_deck.end(), RNG );
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
                    break;
                case Card::SPADES_2:
                    faceCardTotal += 2;
                    break;
                case Card::SPADES_3:
                    faceCardTotal += 3;
                    break;
                case Card::SPADES_4:
                    faceCardTotal += 4;
                    break;
                case Card::SPADES_5:
                    faceCardTotal += 5;
                    break;
                case Card::SPADES_6:
                    faceCardTotal += 6;
                    break;
                case Card::SPADES_7:
                    faceCardTotal += 7;
                    break;
                case Card::SPADES_8:
                    faceCardTotal += 8;
                    break;
                case Card::SPADES_9:
                    faceCardTotal += 9;
                    break;
                case Card::SPADES_10:
                    faceCardTotal += 10;
                    break;
                case Card::SPADES_JACK:
                    faceCardTotal += 10;
                    break;
                case Card::SPADES_QUEEN:
                    faceCardTotal += 10;
                    break;
                case Card::SPADES_KING:
                    faceCardTotal += 10;
                    break;
                case Card::HEARTS_ACE:
                    ++numberOfAces;
                    break;
                case Card::HEARTS_2:
                    faceCardTotal += 2;
                    break;
                case Card::HEARTS_3:
                    faceCardTotal += 3;
                    break;
                case Card::HEARTS_4:
                    faceCardTotal += 4;
                    break;
                case Card::HEARTS_5:
                    faceCardTotal += 5;
                    break;
                case Card::HEARTS_6:
                    faceCardTotal += 6;
                    break;
                case Card::HEARTS_7:
                    faceCardTotal += 7;
                    break;
                case Card::HEARTS_8:
                    faceCardTotal += 8;
                    break;
                case Card::HEARTS_9:
                    faceCardTotal += 9;
                    break;
                case Card::HEARTS_10:
                    faceCardTotal += 10;
                    break;
                case Card::HEARTS_JACK:
                    faceCardTotal += 10;
                    break;
                case Card::HEARTS_QUEEN:
                    faceCardTotal += 10;
                    break;
                case Card::HEARTS_KING:
                    faceCardTotal += 10;
                    break;
                case Card::CLUBS_ACE:
                    ++numberOfAces;
                    break;
                case Card::CLUBS_2:
                    faceCardTotal += 2;
                    break;
                case Card::CLUBS_3:
                    faceCardTotal += 3;
                    break;
                case Card::CLUBS_4:
                    faceCardTotal += 4;
                    break;
                case Card::CLUBS_5:
                    faceCardTotal += 5;
                    break;
                case Card::CLUBS_6:
                    faceCardTotal += 6;
                    break;
                case Card::CLUBS_7:
                    faceCardTotal += 7;
                    break;
                case Card::CLUBS_8:
                    faceCardTotal += 8;
                    break;
                case Card::CLUBS_9:
                    faceCardTotal += 9;
                    break;
                case Card::CLUBS_10:
                    faceCardTotal += 10;
                    break;
                case Card::CLUBS_JACK:
                    faceCardTotal += 10;
                    break;
                case Card::CLUBS_QUEEN:
                    faceCardTotal += 10;
                    break;
                case Card::CLUBS_KING:
                    faceCardTotal += 10;
                    break;
                case Card::DIAMONDS_ACE:
                    ++numberOfAces;
                    break;
                case Card::DIAMONDS_2:
                    faceCardTotal += 2;
                    break;
                case Card::DIAMONDS_3:
                    faceCardTotal += 3;
                    break;
                case Card::DIAMONDS_4:
                    faceCardTotal += 4;
                    break;
                case Card::DIAMONDS_5:
                    faceCardTotal += 5;
                    break;
                case Card::DIAMONDS_6:
                    faceCardTotal += 6;
                    break;
                case Card::DIAMONDS_7:
                    faceCardTotal += 7;
                    break;
                case Card::DIAMONDS_8:
                    faceCardTotal += 8;
                    break;
                case Card::DIAMONDS_9:
                    faceCardTotal += 9;
                    break;
                case Card::DIAMONDS_10:
                    faceCardTotal += 10;
                    break;
                case Card::DIAMONDS_JACK:
                    faceCardTotal += 10;
                    break;
                case Card::DIAMONDS_QUEEN:
                    faceCardTotal += 10;
                    break;
                case Card::DIAMONDS_KING:
                    faceCardTotal += 10;
                    break;
                default: break;// Do Nothing
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
        else if( numberOfAces > 0 )
        {
            total = faceCardTotal + aces11;
        }
        else
        {
            total = faceCardTotal;
        }

        return total;
    }

    bool
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

        // If we are running low on cards, we need to re-shuffle
        // TODO: Make this value configurable based on number of decks
        if( m_deck.size() < 10 )
        {
            return false;
        }
        return true;
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

    bool
    Blackjack::MakePlayerMove( Blackjack::Move a_action )
    {
        bool complete = false;
        switch( a_action )
        {
            case STAY:
                complete = true;
                break;
            case HIT:
            {
                vector<Card::Cards>::iterator card = m_deck.begin();
                m_player.addToHand( *card );
                m_deck.erase( card );
                if( GetCardTotal( m_player.getHand() )> 21)
                {
                    // Uh-Oh, the player has busted.
                    complete = true;
                }
            } break;
            case DOUBLE_DOWN:
            {
                vector<Card::Cards>::iterator card = m_deck.begin();
                m_player.addToHand( *card );
                m_deck.erase( card );
                complete = true;
            }break;
            case SPLIT:
                break;
            default:
                // Not a supported operation
                break;
        }
        return complete;
    }

    void
    Blackjack::TurnDealerCards()
    {
        while( GetCardTotal( m_dealer.getHand() ) < 17 )
        {
            vector<Card::Cards>::iterator card = m_deck.begin();
            m_dealer.addToHand( *card );
            m_deck.erase( card );
        }
    }

    Blackjack::Outcome
    Blackjack::EvaluateWinner()
    {
        Blackjack::Outcome result = Blackjack::OUTCOME_PUSH;
        vector<Card::Cards> player = m_player.getHand();
        vector<Card::Cards> dealer = m_dealer.getHand();

        if( GetCardTotal( player ) > 21 ) // Player bust
        {
            // Loss
            result = Blackjack::OUTCOME_LOSS;
        }
        else if( GetCardTotal( dealer ) == 21 && dealer.size() == 2 ) // Dealer Blackjack
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
        else if( GetCardTotal( dealer) > GetCardTotal( player ) )
        {
            // Dealer beats player
            result = Blackjack::OUTCOME_LOSS;
        }
        else
        {
            // Winner
            result = Blackjack::OUTCOME_WINNER;
        }

        return result;
    }

    // Driver for a CLI
    void Blackjack::PlayBlackjack()
    {
        // Shuffle Cards
        CreateCardDeck();
        ShuffleCardDeck();

        // Give the player some money to start
        Chips& chips = m_player.getChips();
        chips.Credit( 500 );

        bool continueGame = true;
        while( continueGame )
        {
            // Ask a player to place a bet
            cout << "Chip Total: " << chips.GetTotal();
            cout << "Place a bet..." << endl;
            unsigned int input;
            cin >> input;

            // Verify that the player has enough money
            bool enoughMoney = chips.Debit( input );
            if( enoughMoney )
            {
                // Deal the damn cards :)
                bool reshuffle = DealCards();

                // Print the cards
                Card::Cards faceUp = m_dealer.getHand().at( 0 );
                cout << "Dealers Up-Card: " <<  Card::toString( faceUp ) << endl;

                Card::Cards one = m_player.getHand().at( 0 );
                Card::Cards two = m_player.getHand().at( 1 );
                cout << "Your Cards: " << Card::toString( one ) << "  " << Card::toString( two ) << endl;

                // Play game if dealer doesn't have a blackjack.
                if( GetCardTotal( m_dealer.getHand() ) != 21 )
                {

                    // Ask player for action
                    int moveInput = 0;
                    cout << "Make a Move:\n 0: STAY\n 1: HIT\n 2: DOUBLE DOWN\n 3: SPLIT" << endl;
                    cin >> moveInput;
                    while( !MakePlayerMove( static_cast<Blackjack::Move>(moveInput) ) )
                    {
                        // Print the players hand
                        cout << "-----------------------------------" << endl;
                        for( int i = 0; i < m_player.getHand().size(); ++i )
                        {
                            Card::Cards current = m_player.getHand().at( i );
                            cout << Card::toString( current ) << endl;
                        }
                        cout << GetCardTotal( m_player.getHand() ) << endl;
                        cout << "Make a Move:\n 0: STAY\n 1: HIT\n 2: DOUBLE DOWN\n 3: SPLIT" << endl;
                        cin >> moveInput;
                    }

                    TurnDealerCards();
                }

                // Print the Final players hand
                cout << "------------PLAYER-------------" << endl;
                for( int i = 0; i < m_player.getHand().size(); ++i )
                {
                    Card::Cards current = m_player.getHand().at( i );
                    cout << Card::toString( current ) << endl;
                }
                cout << GetCardTotal( m_player.getHand() ) << endl;

                // Print the dealers hand
                cout << "------------DEALER-------------" << endl;
                for( int i = 0; i < m_dealer.getHand().size(); ++i )
                {
                    Card::Cards current = m_dealer.getHand().at( i );
                    cout << Card::toString( current ) << endl;
                }
                cout << GetCardTotal( m_dealer.getHand() ) << endl;

                Blackjack::Outcome outcome = EvaluateWinner();
                switch( outcome )
                {
                    case OUTCOME_WINNER:
                        chips.Credit( input * 2 );
                        cout << "WINNER!" << endl;
                        break;
                    case OUTCOME_LOSS:
                        cout << "Loss :(" << endl;
                        break;
                    case OUTCOME_PUSH:
                        chips.Credit( input );
                        cout << "PUSH." << endl;
                        break;
                    default:
                        break;
                }

                m_player.getHand().clear();
                m_dealer.getHand().clear();

                if( reshuffle )
                {
                    CreateCardDeck();
                    ShuffleCardDeck();
                }

            }
            else if( chips.GetTotal() == 0 )
            {
                cout << "Wha-Wha-Wha... You are broke. The computer is like the governement and will give you some money :)" << endl;
                chips.Credit( 500 );
                cout << "Chip Total: " << chips.GetTotal() << endl;
            }
            else
            {
                cout << "Not enough money to place a bet" << endl;
            }
        }
    }
}
