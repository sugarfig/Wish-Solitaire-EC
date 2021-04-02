//
// Created by Erica on 9/24/2020.
//

#include "Card.h"
void Card::setSuit(int theSuit)
{

    suit.setImage(theSuit);
}

int Card::getSuit()
{
    return suit.getSuit();
}

void Card::setRank(int theRank)
{
    rank.setRank(theRank);
}

int Card::getRank()
{
    return rank.getRank() + 1;
}

Card::Card() : Card(BaseCard::HEARTS, BaseCard::TWO)
{

}

Card::Card(BaseCard::suits suit, BaseCard::ranks rank) //suits suit, BaseCard::ranks rank
{
    isChosen = false;

    if((suit == BaseCard::HEARTS) || (suit == BaseCard::DIAMONDS))
    {
        this->rank.setRank(sf::Color::Red, rank);
    }
    else
    {
        this->rank.setRank(sf::Color::Black, rank);
    }

    this->suit.setImage(suit);

    setPosition(600, 300);
}

Card::Card(int suit, int rank)
{
    isChosen = false;

    if((suit == BaseCard::HEARTS) || (suit == BaseCard::DIAMONDS))
    {
        this->rank.setRank(sf::Color::Red, rank);
    }
    else
    {
        this->rank.setRank(sf::Color::Black, rank);
    }

    this->suit.setImage(suit);

    setPosition(600, 300);
}

Card::Card(BaseCard card) : Card((card.getSuitValue()) , (card.getRankValue() - 1))//: card(card.getSuitValue(), card.getRankValue(false))
{

}

void Card::setPosition(float x, float y)
{
    background.setPosition(x, y);
    rank.setPosition(background.getGlobalBounds());
    suit.setPosition(background.getGlobalBounds());
}
void Card::draw(sf::RenderTarget& window, sf::RenderStates sates) const
{
    window.draw(background);
    window.draw(suit);
    window.draw(rank);
}
//Author: Erica Carballo
void Card::move(int xCurrentMov, int yCurrentMov)
{
    background.move(xCurrentMov, yCurrentMov);

    suit.move(xCurrentMov, yCurrentMov);
    rank.move(xCurrentMov, yCurrentMov);
}

sf::FloatRect Card::getGlobalBounds()
{
    return background.getGlobalBounds();
}

bool operator==(Card& card1, Card& card2)
{
    if((card1.getRank() == card2.getRank()) && (card1.getSuit() == card2.getSuit()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::ostream& operator<<(std::ostream& out, Card& theCard)
{
    out << theCard.getRank() << " of ";
    out << theCard.getSuit();

    return out;

}

bool Card::getIsChosen()
{
    return isChosen;
}

void Card::setIsChosen(bool isChosen)
{
    Card::isChosen = isChosen;
    if(isChosen)
    {
        background.setOutlineColor(sf::Color::Cyan);
        background.setOutlineThickness(10);
    }
    else
    {
        background.setOutlineThickness(0);
    }


}

void Card::setTheStackNum(int theStackNum)
{
    stackNum = theStackNum;
}

int Card::getTheStackNum()
{
    return stackNum;
}
