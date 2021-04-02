//
// Created by Erica on 12/8/2020.
//

#include "CardPiles.h"

int CardPiles::xpositions[8];
CardPiles::CardPiles()
{

}

void CardPiles::addToPile(Card cardToAdd)
{
    cardStack.push(cardToAdd);
}

void CardPiles::removeFromPile()
{
    cardStack.pop();
}

void CardPiles::setIsPileChosen(bool theIsChosen)
{
    isChosen = theIsChosen;
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

Card CardPiles::at(int index)
{

}
bool CardPiles::getIsPileChosen()
{
    return isChosen;
}

void CardPiles::addEvents(sf::RenderWindow& window, sf::Event event)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
        sf::FloatRect cardBounds = cardStack.top()->getGlobalBounds();

        if(cardBounds.contains(mpos))
        {
            if(cardStack.top()->getIsChosen())
            {
                cardStack.top()->setIsChosen(false);
            }
            else
            {
                cardStack.top()->setIsChosen(true);
            }

        }
    }
}

CardPiles::states CardPiles::getState() const {
    return state;
}
//Author: Erica Carballo
void CardPiles::setState(CardPiles::states state) {
    CardPiles::state = state;
}
void CardPiles::draw(sf::RenderWindow& window, sf::Event event) const
{
    switch(state)
    {
        case SHOW:
                {
                    CardStack temp = cardStack;
                    int size = cardStack.getSize();
                    for(int i=0; i<size; i++)
                        window.draw(temp.pop());
                }
            break;
        case CLICKED:

            break;
    }


}
void CardPiles::update(sf::RenderWindow& window)
{
    if(state == CLICKED)
    {

    }
        //add the
}