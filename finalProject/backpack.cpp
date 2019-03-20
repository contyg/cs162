//TODO: description
#include "backpack.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

Backpack::Backpack()
{
    head = nullptr;
	tail = nullptr;
    itemCount = 0;
    trifectaNotUsed = true;
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
    cout << "\n\033[0;33mYou've added a new piece of the trifecta to you backpack: \033[0m\n\033[1;33m" << item << "\033[0m\n" << endl;
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
		cout << "\n\033[0;33mThere's nothing in your backpack yet!\033[0m\n" << endl;
	}
    else 
    {
        cout << "\n\033[0;33mYour backpack contains:\033[0m\033[1;33m" << endl;
		Item* node = head;
		while (node != nullptr) 
        {
			cout << node->val;
			node = node->next;
		}

		cout << "\033[0m\n" << endl;
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

bool Backpack::getTrifectaNotUsed()
{
    return trifectaNotUsed;
}


void Backpack::setTrifectaUsed(bool val)
{
    trifectaNotUsed = val;
}

