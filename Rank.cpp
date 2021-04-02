//
// Created by Erica on 9/24/2020.
//

#include "Rank.h"

Rank::Rank() : Rank(sf::Color::Black, BaseCard::ACE)//Rank(sf::Color::Red, BaseCard::ACE)
{

}

Rank::Rank(sf::Color color, BaseCard::ranks rank)
{
    if(!font.loadFromFile("../OpenSans-Bold.ttf"))
    {
        exit(1);
    }
    setFont(font);
    setFillColor(sf::Color::Black);
    setCharacterSize(50);
    setString(ranksConvert[rank]);
}
void Rank::setPosition(sf::FloatRect bounds)
{
    sf::Text::setPosition({bounds.left + bounds.width/2 - getGlobalBounds().width/2, bounds.top + bounds.height/2 - getGlobalBounds().height/2});

}

void Rank::setRank(sf::Color color, BaseCard::ranks rank)
{
    if(!font.loadFromFile("../OpenSans-Bold.ttf"))
    {
        exit(1);
    }
    setFont(font);
    setFillColor(sf::Color::Black);
    setCharacterSize(50);
    setString(ranksConvert[rank]);
}
//Author: Erica Carballo
void Rank::setRank(sf::Color color, int rank)
{
    setRank(rank);
    if(!font.loadFromFile("../OpenSans-Bold.ttf"))
    {
        exit(1);
    }
    setFont(font);
    setFillColor(sf::Color::Black);
    setCharacterSize(50);
    setString(ranksConvert[rank]);
}

void Rank::setRank(int theRank)
{
    rank = theRank;
    setString(ranksConvert[rank]);
}

int Rank::getRank()
{
    return rank;
}


