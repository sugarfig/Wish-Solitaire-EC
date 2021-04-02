//
// Created by Erica on 10/12/2020.
//

#ifndef POKERANALYSIS_DECK_H
#define POKERANALYSIS_DECK_H
#include "Card.h"
#include <iostream>

class Deck
{
public:
    Card& dealCard();
    Card getCardAt(int index);
    Deck();
    //Author: Erica Carballo
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck);
    void shuffle();

private:
    int cardIndex = 0;
    Card deck[52];
    const int DECK_SIZE = 32;
};


#endif //POKERANALYSIS_DECK_H
