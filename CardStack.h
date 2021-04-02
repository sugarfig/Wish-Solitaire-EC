//
// Created by Erica on 12/7/2020.
//

#ifndef BOUNCINGOBJECTS_CARDSTACK_H
#define BOUNCINGOBJECTS_CARDSTACK_H
#include "Card.h"
#include "Node.h"

class CardStack
{
private:
    Node* head;
    Node* tail;
    Node* createNode(Card item);
    int size;

public:
    CardStack();
    Card pop();
    //Author: Erica Carballo
    void push(Card newCard);
    Card* top();
    int getSize() const;

};


#endif //BOUNCINGOBJECTS_CARDSTACK_H
