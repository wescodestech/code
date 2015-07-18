//
//  Chips.cpp
//  Cards
//
//  Created by Wesley Howell on 6/27/15.
//  Copyright (c) 2015 Wesley Howell. All rights reserved.
//
#include "Chips.h"

namespace CardGames
{
    Chips::Chips()
    {
        m_total = 0;
    }

    Chips::~Chips()
    {
        //We aren't holding any pointers
    }

    Chips::Chips
    (
     const unsigned int a_amount
    )
    {
        m_total = a_amount;
    }

    bool
    Chips::Debit
    (
     const unsigned int a_amount
    )
    {
        if( a_amount < m_total )
        {
            m_total -= a_amount;
            return true;
        }
        return false;
    }

    bool
    Chips::Credit
    (
     const unsigned int a_amount
    )
    {
        m_total += a_amount;
        return true;
    }

    unsigned int
    Chips::GetTotal()
    {
        return m_total;
    }
}