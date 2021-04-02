//
// Created by Erica on 12/2/2020.
//

#include "DeckQueue.h"

DeckQueue::DeckQueue()
{
    head = nullptr;
    tail = nullptr;
}

void DeckQueue::push(Card theCard)
{
    Node* temp = createNode(theCard);

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
}
//Author: Erica Carballo
Card DeckQueue::pop()
{
    Card tempCard = tail->data;

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    return tempCard;
}

Node* DeckQueue::createNode(Card item)
{
    Node* n = new Node;
    n->data = item;
    n->next = nullptr;
    n->prev = nullptr;

    return n;
}