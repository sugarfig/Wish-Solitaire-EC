//
// Created by Erica on 12/8/2020.
//

#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
    if(!texture.loadFromFile("../SplashScreen.png"))
    {
        exit(1);
    }
    background.setTexture(texture);
}

void SplashScreen::draw(sf::RenderTarget& window, sf::RenderStates rs) const
{
    Button button1;
    button1.setText("Play");
    button1.setPosition(850,650);
//Author: Erica Carballo
    button.getGlobalBounds() = button1.getGlobalBounds();
    window.draw(background);
    window.draw(button1);
}

sf::FloatRect SplashScreen::getButtonBounds() const
{
    sf::FloatRect temp;
    temp.top = 650;
    temp.left = 850;
    temp.width = 200;
    temp.height = 100;
    return temp;
}
