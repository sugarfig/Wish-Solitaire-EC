//
// Created by Erica on 12/8/2020.
//

#ifndef BOUNCINGOBJECTS_BUTTON_H
#define BOUNCINGOBJECTS_BUTTON_H
#include <SFML/Graphics.hpp>


class Button : public sf::Drawable, sf::Transformable
{
public:
    Button();
    void setText(std::string theText);
    void setPosition(float theX, float theY);
    //Author: Erica Carballo
    virtual void draw(sf::RenderTarget& window, sf::RenderStates rs) const;
    sf::FloatRect getGlobalBounds() const;

private:
    sf::RectangleShape rc;
    sf::Font font;
    sf::Text text;
};


#endif //BOUNCINGOBJECTS_BUTTON_H
