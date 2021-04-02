//
// Created by Erica on 12/2/2020.
//

#include "WishSolitaireGame.h"
#include "DeckQueue.h"
#include "CardStack.h"
#include "Button.h"
#include "SplashScreen.h"
#include "CardPiles.h"


void WishSolitaireGame::run()
{
    sf::RenderWindow window({1920, 1080, 32}, "Wish Solitaire");
    Deck d;
    SplashScreen ss;
    DeckQueue deckQueue;

    d.shuffle();

    for(int i = 0; i < 32; i++)
    {

        deckQueue.push(d.dealCard());

    }

    CardStack discard;

    CardStack* c = new CardStack[8];

    for(int i = 0; i < 32; i+=8)
    {
        for(int j = 0; j < 8; j++)
        {
            c[j].push(deckQueue.pop());
            c[j].top()->setTheStackNum(j);

        }
    }

//    CardPiles* c = new CardPiles[8];
//
//    for(int i = 0; i < 8; i++)
//    {
//
//        for(int j = 0; j < 4; j++)
//        {
//          //  std::cout << deckQueue.pop() << std::endl;
//            c[i].addToPile(deckQueue.pop());
//            //c[i].setTheStackNum(4);
//
//        }
//    }

    int arr[8] = {185, 385, 585, 785, 985, 1185, 1385, 1585}; // 270 VERTICAL POSITION

    bool buttonClicked = false;

    while(window.isOpen())
    {

        sf::Event event;

        while(window.pollEvent(event))
        {

            if(event.type == sf::Event::Closed)
            {
                window.close();

            }
            //listen for events and change the state of objects
            //addEvents(window, event);
        }

        //update the objects according the state that was made in addEvents
        //update();

        window.clear(sf::Color{48,213,200});

//        for(int i=0; i<8; i++)
//            window.draw(c[i]);
//        window.display();

        int counter = 0, arr1[2] = {0};


        if(!buttonClicked)
        {
            window.draw(ss);


            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
                sf::FloatRect buttonBounds = ss.getButtonBounds();
                if(buttonBounds.contains(mpos))
                {
                    buttonClicked = true;
                }
            }
        }
        else
        {
            for(int i = 0; i < 8; i++)
            {
                if(c[i].getSize() != 0)
                {
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
                        sf::FloatRect cardBounds = c[i].top()->getGlobalBounds();

                        if(cardBounds.contains(mpos))
                        {
                            if(c[i].top()->getIsChosen())
                            {
                                c[i].top()->setIsChosen(false);
                            }
                            else
                            {
                                c[i].top()->setIsChosen(true);
                            }

                            while(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                            {

                            }

                        }
                    }

                    c[i].top() -> setPosition(arr[i], 270);
                    Card* temp = c[i].top();

                    window.draw(*temp);

                    if(c[i].top()->getIsChosen())
                    {
                        arr1[counter] = i;
                        counter++;
                        if(counter == 2)
                        {
                            c[arr1[0]].top()->setIsChosen(false);
                            c[arr1[1]].top()->setIsChosen(false);
                            if(c[arr1[0]].top()->getRank() == c[arr1[1]].top()->getRank())
                            {
                                discard.push(c[arr1[0]].pop());
                                discard.push((c[arr1[1]]).pop());
                            }
                        }
                    }


                }

            }
//Author: Erica Carballo
            if(discard.getSize() > 0)
            {
                Card* tempDiscard = discard.top();
                tempDiscard->setPosition(900, 600);

                window.draw(*tempDiscard);

                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
                    sf::FloatRect cardBounds = discard.top()->getGlobalBounds();

                    if(cardBounds.contains(mpos))
                    {
                        c[discard.top()->getTheStackNum()].push(discard.pop());
                        c[discard.top()->getTheStackNum()].push(discard.pop());
                        while(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {

                        }
                    }

                }

            }
        }

        window.display();

    }

}