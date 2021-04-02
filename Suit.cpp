//
// Created by Erica on 9/24/2020.
//

#include "Suit.h"

void Suit::setSuit(int theSuit)
{
    suit = theSuit;
}

int Suit::getSuit()
{
    return suit;
}

std::string Suit::getImagePath(BaseCard::suits suit)
{

    switch(suit)
    {
        case BaseCard::HEARTS:
            return "../Heart.png";
        case BaseCard::DIAMONDS:
            return "../Diamond.png";
        case BaseCard::CLUBS:
            return "../Clubs.png";
        case BaseCard::SPADES:
            return "../Spades.png";
    }

}

std::string Suit::getImagePath(int suit)
{
    switch(suit)
    {
        case 0:
            return "../Heart.png";
        case 1:
            return "../Diamond.png";
        case 2:
            return "../Clubs.png";
        case 3:
            return "../Spades.png";
        default:
            exit(20);
    }
}
//Author: Erica Carballo
void Suit::setPosition(sf::FloatRect bounds)
{
    top.setPosition(bounds.left + 10, bounds.top + 10);
    bottom.setPosition(bounds.left + bounds.width - 10, bounds.top + bounds.height - 10);
}

void Suit::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(top);
    window.draw(bottom);
}

void Suit::setImage(BaseCard::suits suit)
{
    if(!texture.loadFromFile(getImagePath(suit)))
    {
        exit(1);
    }
    top.setTexture(texture);
    bottom.setTexture(texture);
    bottom.rotate(180);
    top.scale(0.1f, 0.1f);
    bottom.scale(0.1f, 0.1f);
}
void Suit::setImage(int suit)
{
    setSuit(suit);
    if(!texture.loadFromFile(getImagePath(suit)))
    {
        exit(1);
    }
    top.setTexture(texture);
    bottom.setTexture(texture);
}

void Suit::move(int xCurrentMov, int yCurrentMov)
{
    top.move(xCurrentMov, yCurrentMov);
    bottom.move(xCurrentMov, yCurrentMov);
}