#include "backpack.hpp"
#include <iostream>

using std::cout;
using std::endl;

Backpack::Backpack()
{
    head = nullptr;
	tail = nullptr;
    itemCount = 0;
    trifectaUsed = false;
    full = false;
}

Backpack::~Backpack()
{
    Item* node = head;
    while(node != nullptr)
    {
        Item* trash = node;
        node = node->next;
        delete trash;
    }
}

// adds to tail
void Backpack::addItem(string item)
{ 
    cout << "You won a new piece of the trifecta: " << item << endl;
    if (tail == nullptr) // check if list is empty
    {
		tail = new Item(item);
        head = tail;
        itemCount++;
	} 
    else 
    {
		tail = new Item(item, tail, nullptr);
        tail->prev->next = tail;
        itemCount++;
    }
    
    if (itemCount == 3)
    {
        full = true;
    }
}

void Backpack::printContents()
{ 
    if (tail == nullptr) // check if list is empty
    {
		cout << "\033[0;33mThere's nothing in your backpack yet!\033[0m\n" << endl;
	}
    else 
    {
        cout << "\033[0;33mYour backpack contains:\033[0m" << endl;
		Item* node = head;
		while (node != nullptr) 
        {
			cout << node->val << ", ";
			node = node->next;
		}

		cout << "\n" << endl;
	}
}

int Backpack::getItemCount()
{
    return itemCount;
}

bool Backpack::getFull()
{
    return full;
}

bool Backpack::getTrifectaUsed()
{
    return trifectaUsed;
}


void Backpack::setTrifectaUsed(bool val)
{
    trifectaUsed = val;
}

