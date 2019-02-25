#include "queue.hpp"
#include "validate.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Queue::Queue()
{
    head = nullptr;
    tail = nullptr;
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
        head->next = head;
        head->prev = head;
        tail = head;
	} 		
    else 
    {
        QueueNode *temp = tail;
        tail->next = new QueueNode(val, nullptr, temp);
		tail = tail->next;
	}
}

void Queue::removeFront()
{
    if(head->next == nullptr && head->prev == nullptr) //only 1 value
    {
        delete head;
        head = nullptr;
    }
    else
    {
        QueueNode *temp = nullptr;

        temp = head;
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
    
    cout << head->val << " ";

    QueueNode* node = head;
    while (node != nullptr) 
    {
        cout << node->val << " ";
        node = node->next;
    }

    cout << "\n" << endl;
}