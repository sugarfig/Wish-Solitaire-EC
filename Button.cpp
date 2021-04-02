//
// Created by Erica on 12/8/2020.
//

#include "Button.h"

Button::Button()
{
    rc.setSize({200.f, 100.f});
    rc.setFillColor(sf::Color::White);
    rc.setOutlineColor(sf::Color{255, 105, 180});
    rc.setOutlineThickness(3);
}

void Button::setText(std::string theText)
{
    text.setString(theText);
    if(!font.loadFromFile("../OpenSans-Bold.ttf"))
    {
        exit(1);
    }
    text.setFont(font);
    text.setFillColor(sf::Color{255, 128,169});
    text.setCharacterSize(50);
}
//Author: Erica Carballo
void Button::setPosition(float theX, float theY)
{
    rc.setPosition(theX, theY);
    text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);
    text.setPosition(theX + rc.getGlobalBounds().width/2 , theY + rc.getGlobalBounds().height/2);
}

void Button::draw(sf::RenderTarget& window, sf::RenderStates rs) const
{
    window.draw(rc);
    window.draw(text);
}

sf::FloatRect Button::getGlobalBounds() const
{
    return rc.getGlobalBounds();
}