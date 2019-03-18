#include "backpack.hpp"
#include <iostream>

using std::cout;
using std::endl;

Backpack::Backpack()
{
    head = nullptr;
	tail = nullptr;
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

void Backpack::addItem(string item)
{
    if (head == nullptr) // check if list is empty
    {
		head = new Item(item);
		tail = head;
	} 		
    else 
    {
		head = new Item(item, nullptr, head);
		head->next->prev = head;
	}
}

void Backpack::printContents()
{ 
    if (tail == nullptr) // check if list is empty
    {
		cout << "There's nothing in your backpack yet!\n" << endl;
	}
    else 
    {
        cout << "\033[1;33mYour backpack contains:\033[0m" << endl;
		Item* node = head;
		while (node != nullptr) 
        {
			cout << node->val << ", ";
			node = node->next;
		}

		cout << "\n" << endl;
	}
}

