/********************************************************************* 
** Program name: Fantasy Combat Part 2   
** Description: Definition of linked list functions  
*********************************************************************/

#include "DoublyLinkedList.hpp" 
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
	tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
    DLListNode* node = head;
    while(node != nullptr)
    {
        DLListNode* trash = node;
        node = node->next;
        delete trash;
    }
}

void DoublyLinkedList::addHead(Character* type)
{
    if (head == nullptr) // check if list is empty
    {
		head = new DLListNode(type);
		tail = head;
	} 		
    else 
    {
		head = new DLListNode(type, nullptr, head);
		head->next->prev = head;
	}
}

void DoublyLinkedList::printList()
{
    cout << "\033[1;33mLosers List:\033[0m" << endl;
    if (tail == nullptr) // check if list is empty
    {
		cout << "There aren't any elements to print. \n" << endl;
	}
    else 
    {
		DLListNode* node = head;
		while (node != nullptr) 
        {
			cout << node->type->getName() << " ";
			node = node->next;
		}

		cout << "\n" << endl;
	}
}