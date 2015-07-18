//
//  Chips.h
//  Cards
//
//  Created by Wesley Howell on 6/27/15.
//  Copyright (c) 2015 Wesley Howell. All rights reserved.
//

#ifndef Cards_Chips_h
#define Cards_Chips_h

namespace CardGames
{
    enum Chip
    {
        CHIP_ONE
        , CHIP_FIVE
        , CHIP_TWENTY_FIVE
        , CHIP_ONE_HUNDRED

    };

class Chips
{
// Enum for chip values (1, 5, 25, 100)
// Function for debit/credit
// Function for total

public:
    Chips();
    ~Chips();

    Chips
        (
        const unsigned int a_amount
        );

    bool
    Debit
        (
        const unsigned int a_amount
        );

    bool
    Credit
        (
        const unsigned int a_amount
        );

    unsigned int
    GetTotal();

private:
    unsigned int m_total;

};

}

#endif
