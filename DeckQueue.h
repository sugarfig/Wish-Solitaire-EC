//
// Created by Erica on 12/2/2020.
//

#ifndef BOUNCINGOBJECTS_DECKQUEUE_H
#define BOUNCINGOBJECTS_DECKQUEUE_H
#include "Node.h"
#include "Card.h"

class DeckQueue
{
public:
    DeckQueue();
    void push(Card theCard);
    Card pop();
//Author: Erica Carballo

private:
    Node* head;
    Node* tail;
    Node* createNode(Card item);
};


#endif //BOUNCINGOBJECTS_DECKQUEUE_H
