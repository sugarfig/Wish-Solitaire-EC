//
// Created by Erica on 12/7/2020.
//

#include "CardStack.h"

CardStack::CardStack()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

Card CardStack::pop()
{
    Card tempCard = head->data;
    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
    size--;
    return tempCard;
}
//Author: Erica Carballo
void CardStack::push(Card newCard)
{
    Node* temp = createNode(newCard);

    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        temp->prev = nullptr;
        head = temp;
    }
    size++;
}

Card* CardStack::top()
{
    return &head->data;
}

Node* CardStack::createNode(Card item)
{
    Node* n = new Node;
    n->data = item;
    n->next = nullptr;
    n->prev = nullptr;

    return n;
}

int CardStack::getSize() const
{
    return size;
}