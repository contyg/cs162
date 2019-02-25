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
        head->next = head;
	} 		
    else 
    {
		head->prev = head;
		head->next = new QueueNode(val, head, head->prev);
	}
}

void Queue::removeFront()
{
    QueueNode *temp = nullptr;
    if (isEmpty())
    {
		cout << "There aren't any elements to delete.\n" << endl;
	} 
    else
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    
}

int Queue::getFront()
{
    if (isEmpty())
    {
		cout << "There isn't a front because the queue is empty.\n" << endl;
        return head->val;
	} 
    else
    {
        return head->val;
    }  
}

void Queue::printQueue()
{
    cout << "\033[1;33mList:\033[0m" << endl;
    if (head == nullptr) // check if empty
    {
		cout << "There aren't any elements to print. \n" << endl;
	}
    else 
    {
		QueueNode* node = head;
		while (node != nullptr) 
        {
			cout << node->val << " ";
			node = node->next;
		}

		cout << "\n" << endl;
	}
}

