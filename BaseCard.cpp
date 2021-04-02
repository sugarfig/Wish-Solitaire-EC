//
// Created by Erica on 10/1/2020.
//

#include "BaseCard.h"

BaseCard::BaseCard()
{
    suit = HEARTS;
    rank = ACE;
}
BaseCard::BaseCard(suits suit, ranks rank) : suit(suit), rank(rank)
{

}

void BaseCard::setSuits(suits suit)
{
    this->suit = suit;
}

void BaseCard::setRank(ranks rank)
{
    this-> rank = rank;
}

int BaseCard::getSuitValue() const
{
    return suit;
}

std::string BaseCard::getSuit() const
{
    return suitToString(suit);
}

std::string BaseCard::getRank() const
{
    return rankToString(rank);
}

std::string BaseCard::getRankFull() const
{
    return rankToFullString(rank);
}

int BaseCard::getRankValue(bool cardValue)const
{
    if (cardValue)
    {
        switch(rank)
        {
            case ACE:
                return 11;
            case TWO:
                return 2;
            case THREE:
                return 3;
            case FOUR:
                return 4;
            case FIVE:
                return 5;
            case SIX:
                return 6;
            case SEVEN:
                return 7;
            case EIGHT:
                return 8;
            case NINE:
                return 9;
            case TEN:
            case JACK:
            case QUEEN:
            case KING:
                return 10;
        }
    }
}

std::ostream& operator<<(std::ostream& out, const BaseCard& card)
{
    out << card.getRankFull() + " of " << card.getSuit();
    return out;
}
//Author: Erica Carballo
int operator+(const BaseCard& card1, const BaseCard& card2)
{
    return card1.getRankValue() + card2.getRankValue();
}

std::string BaseCard::rankToString(ranks rank, bool fullWord) const
{
//converting rank to string. get enum and pass here convert zero to A, 13 to k 11 to j.

    switch(rank)
    {
        case ACE:
            return "A";
        case TWO:
            return "2";
        case THREE:
            return "3";
        case FOUR:
            return "4";
        case FIVE:
            return "5";
        case SIX:
            return "6";
        case SEVEN:
            return "7";
        case EIGHT:
            return "8";
        case NINE:
            return "9";
        case TEN:
            return "10";
        case JACK:
            return "J";
        case QUEEN:
            return "Q";
        case KING:
            return "K";
        default: "";
    }

}


std::string BaseCard::rankToFullString(ranks rank) const
{
    switch(rank)
    {
        case ACE:
            return "Ace";
        case TWO:
            return "Two";
        case THREE:
            return "Three";
        case FOUR:
            return "Four";
        case FIVE:
            return "Five";
        case SIX:
            return "Six";
        case SEVEN:
            return "Seven";
        case EIGHT:
            return "Eight";
        case NINE:
            return "Nine";
        case TEN:
            return "Ten";
        case JACK:
            return "Jack";
        case QUEEN:
            return "Queen";
        case KING:
            return "King";
        default: "";


    }



}

std::string BaseCard::suitToString(suits suit) const
{
    switch(suit)
    {
        case HEARTS:
            return "Hearts";
        case DIAMONDS:
            return "Diamonds";
        case CLUBS:
            return "Clubs";
        case SPADES:
            return "Spades";
        default:
            return "";
    }
}