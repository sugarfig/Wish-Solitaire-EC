//
// Created by Erica on 9/24/2020.
//

#ifndef CARDLAB_CARD_H
#define CARDLAB_CARD_H
#include "Background.h"
#include "Suit.h"
#include "Rank.h"
#include "BaseCard.h"

class Card : public sf::Drawable, public sf::Transformable , public BaseCard
{
private:
    Background background;
    Suit suit;
    Rank rank;
    bool isChosen;
    int stackNum;

public:
    Card();
    Card(BaseCard::suits suit, BaseCard:: ranks rank);
    Card(int suit, int rank);
    Card(BaseCard card);
    //Author: Erica Carballo
    void setPosition(float x, float y);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates sates) const;
    void move(int xCurrentMov, int yCurrentMov);
    sf::FloatRect getGlobalBounds();
    void setRank(int theRank);
    int getRank();
    void setSuit(int theSuit);
    int getSuit();
    friend bool operator==(Card& card1, Card& card2);
    friend std::ostream& operator<<(std::ostream& out, Card& theCard);
    bool getIsChosen();
    void setIsChosen(bool isChosen);
    void setTheStackNum(int theStackNum);
    int getTheStackNum();
};



#endif //CARDLAB_CARD_H
