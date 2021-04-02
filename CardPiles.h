//
// Created by Erica on 12/8/2020.
//

#ifndef BOUNCINGOBJECTS_CARDPILES_H
#define BOUNCINGOBJECTS_CARDPILES_H
#include "Background.h"
#include "CardStack.h"
#include "Card.h"

class CardPiles : public sf::Drawable, public sf::Transformable
{
public:
    CardPiles();
    void addToPile(Card cardToAdd);
    void removeFromPile();
    void setIsPileChosen(bool theIsChosen);
    bool getIsPileChosen();
    void addEvents(sf::RenderWindow& window, sf::Event event);
    Card at(int index);
    //Author: Erica Carballo
    enum states {CLICKED, SHOW, HIDE};
    virtual void draw(sf::RenderWindow& window, sf::Event event) const;
    void update(sf::RenderWindow& window);
private:

    bool isChosen;
    Background background;
    CardStack cardStack;
    static int xpositions[8];
    int prevPositions[8];
    states state;
public:
    states getState() const;

    void setState(states state);

};


#endif //BOUNCINGOBJECTS_CARDPILES_H
