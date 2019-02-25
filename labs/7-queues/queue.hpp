#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

class Queue {

private:
    // create circular linked list 
    struct QueueNode 
    {
        int val;
        QueueNode *next;
        QueueNode *prev;
        QueueNode(int v, QueueNode *n = nullptr, QueueNode *p = nullptr)
        {
            val = v;
            next = n;
            prev = p;
        }
    };
    QueueNode *head;

public:

    Queue();
    ~Queue();

    bool isEmpty();
    void addBack(int val);
    void removeFront();
    int getFront();
    void printQueue();
};

#endif