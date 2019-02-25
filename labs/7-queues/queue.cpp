#include "queue.hpp"
#include "validate.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Queue::Queue()
{
    head = nullptr;
}

Queue::~Queue()
{
    QueueNode *trash = head;

    while (trash != nullptr)
    {
        head = head->next;
        trash->next = nullptr;
        delete trash;
        trash = head;
    }
}

bool Queue::isEmpty()
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Queue::addBack(int val)
{
    if (isEmpty())
    {
        head = new QueueNode(val);
        //single node points to self in both directions
        head->next = head;
        head->prev = head;
	} 		
    else 
    {
        //points to last element of list cuz circular
        head->prev = new QueueNode(val, head, head->prev);
        // (head->prev)->prev gets to formet last node
        // (lastNode->next) points to new last node
        // essentially updates the link
        // see doubly-linked-circular pic for diagram
		head->prev->prev->next = head->prev;
	}
}

void Queue::removeFront()
{
    //when only 1 value, next & prev points to self
    if(head->next == head && head->prev == head) 
    {
        delete head;
        head = nullptr;
    }
    else
    {
        QueueNode *temp = nullptr;
        temp = head;
        // move head to next value in list
        head = head->next;
        delete temp;
    }
}

int Queue::getFront()
{
    return head->val;
}

void Queue::printQueue()
{
    cout << "\033[1;33mList:\033[0m" << endl;
    
    QueueNode* node = head;
    while (node != nullptr) 
    {
        cout << node->val << " ";
        node = node->next;
    }

    cout << "\n" << endl;
}