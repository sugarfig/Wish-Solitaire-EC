//
// Created by Erica on 9/24/2020.
//

#ifndef CARDLAB_SUIT_H
#define CARDLAB_SUIT_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "BaseCard.h"

class Suit : public sf::Drawable, public sf::Transformable
{
private:
    sf::Sprite top;
    sf::Sprite bottom;
    sf::Texture texture;
    int suit;

public:
    void setSuit(int theSuit);
    int getSuit();
    //Author: Erica Carballo
    void setPosition(sf::FloatRect bounds);
    std::string getImagePath(BaseCard::suits suit);
    std::string getImagePath(int suit);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setImage(BaseCard::suits suit);
    void setImage(int suit);
    void move(int xCurrentMov, int yCurrentMov);


};


#endif //CARDLAB_SUIT_H
