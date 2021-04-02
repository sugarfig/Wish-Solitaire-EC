//
// Created by Erica on 10/1/2020.
//

#ifndef CARDLAB2_BASECARD_H
#define CARDLAB2_BASECARD_H
#include <string>

class BaseCard
{
public:
    enum suits
    {
        HEARTS,
        DIAMONDS,
        CLUBS,
        SPADES
    };
    enum ranks
    {
        ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK,
        QUEEN, KING
    };

    void setSuits(suits suit);
    void setRank(ranks rank);
    int getSuitValue() const;
    std::string getRank() const;
    std::string getRankFull() const;
    std::string getSuit() const;
    //Author: Erica Carballo
    int getRankValue(bool cardValue = true) const;
    friend std::ostream& operator<<(std::ostream& out, const BaseCard& card);
    friend int operator+(const BaseCard& card1, const BaseCard& card2);
    BaseCard();
    BaseCard(suits suit, ranks rank);

private:
    suits suit;
    ranks rank;

protected:
    std::string rankToString(ranks rank, bool fullWord = false) const;
    std::string suitToString(suits suit) const;
    std::string rankToFullString(ranks rank) const;

};


#endif //CARDLAB2_BASECARD_H
