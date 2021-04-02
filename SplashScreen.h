//
// Created by Erica on 12/8/2020.
//

#ifndef BOUNCINGOBJECTS_SPLASHSCREEN_H
#define BOUNCINGOBJECTS_SPLASHSCREEN_H
#include <SFML/Graphics.hpp>
#include "Button.h"

class SplashScreen : public sf::Drawable, public sf::Transformable//public sf::Shape
{
public:
    SplashScreen();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates rs) const;
    sf::FloatRect getButtonBounds() const;
//Author: Erica Carballo
private:
    sf::Sprite background;
    sf::Texture texture;
    Button button;
};


#endif //BOUNCINGOBJECTS_SPLASHSCREEN_H
