/********************************************************************* 
** Program name: Fantasy Combat Part 2  
** Description: Declaration of Queue Class 
*********************************************************************/

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "character.hpp"

class Queue {

private:
    // create circular linked list 
    struct QueueNode 
    {
        Character* type;
        QueueNode* next;
        QueueNode* prev;
        QueueNode(Character* t = nullptr, QueueNode* n = nullptr, QueueNode* p = nullptr)
        {
            type = t;
            next = n;
            prev = p;
        }
    };
    QueueNode* head;

public:
    Queue();
    ~Queue();

    bool isEmpty();
    void addBack(Character* type);
    void removeFront();
    Character* getFront();
    void printQueue();
};

#endif