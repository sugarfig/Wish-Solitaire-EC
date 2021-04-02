//
// Created by Erica on 10/12/2020.
//

#include "Deck.h"
#include "time.h"

Card& Deck::dealCard()
{
    cardIndex++;
    return deck[cardIndex - 1];

}

Card Deck::getCardAt(int index)
{
    return deck[index - 1];
}

Deck::Deck()
{
    int index;
    index = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if(!(j >= 1 && j <= 5))
            {
                deck[index].setSuit(i);
                deck[index].setRank(j);
                index++;
            }

        }

    }
}
//Author: Erica Carballo
std::ostream& operator<<(std::ostream& out, const Deck& deck)
{
    for (int i = 0; i < 32; i++)
    {
        out << i + 1 << ": ";
        out << deck.deck[i];
        out << std::endl;
    }
}

void Deck::shuffle()
{
    bool arr[32] = {false};
    Card temp[DECK_SIZE], nullCard;
    int index, i;
    srand(time(NULL));
    index = rand() % DECK_SIZE;
    i = 0;

    while (i < 32)
    {
        index = rand() % 32;
        if (arr[index] == false)
        {
            temp[i] = deck[index];
            arr[index] = true;
            i++;
        }
    }

    for (int j = 0; j < DECK_SIZE; j++)
    {
        deck[j] = temp[j];
    }
    cardIndex = 0;
}