//
// Created by Erica on 9/24/2020.
//

#ifndef CARDLAB_RANK_H
#define CARDLAB_RANK_H
#include <SFML/Graphics.hpp>
#include "BaseCard.h"

class Rank : public sf::Text
{
private:
    sf::Font font;
    std::string ranksConvert[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    int rank;

public:
    Rank();
    Rank(sf::Color color, BaseCard::ranks rank);
    void setRank(int theRank);
    int getRank();
    //Author: Erica Carballo
    void setPosition(sf::FloatRect bounds);
    void setRank(sf::Color color, BaseCard::ranks rank);
    void setRank(sf::Color color, int rank);


};


#endif //CARDLAB_RANK_H
