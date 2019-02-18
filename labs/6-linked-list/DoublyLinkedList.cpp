/********************************************************************* 
** Program name: Doubly-linked List Lab  
** Description: Definition of linked list functions  
*********************************************************************/

#include "DoublyLinkedList.hpp" 
#include <iostream>

using std::cout;
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

void DoublyLinkedList::addHead(int newHead)
{
    if (head == nullptr) 
    {
		head = new DLListNode(newHead);
		tail = head;
	} 		
    else 
    {
		head = new DLListNode(newHead, nullptr, head);
		head->next->prev = head;
	}
}

void DoublyLinkedList::addTail(int newTail)
{
    if (tail == nullptr) 
    {
		tail = new DLListNode(newTail);
		head = tail;
	} 
    else 
    {
		tail = new DLListNode(newTail, tail, nullptr);
		tail->prev->next = tail;
	}
}

void DoublyLinkedList::deleteFirstNode()
{
    if (head == nullptr) 
    {
		cout << "There aren't any elements to delete." << endl;
	} 
    else if (head->next == nullptr) 
    {
		delete head;
		head = nullptr;
		tail = head;
	} 
    else 
    {
		DLListNode* trash = head;
		head = head->next;
		head->prev = nullptr;
		delete trash;
	}
}

void DoublyLinkedList::deleteLastNode()
{
    if (tail == nullptr) 
    {
		cout << "There aren't any elements to delete." << endl;
	} 
    else if (tail->prev == nullptr) 
    {
		delete tail;
		tail = nullptr;
		head = tail;
	}
    else 
    {
		DLListNode* trash = tail;
		tail = tail->prev;
		tail->next = nullptr;		
		delete trash;
	}
}

void DoublyLinkedList::printReverseList()
{
    cout << "\033[0;31mReversed List:\033[0m" << endl;
    if (tail == nullptr) 
    {
		cout << "There aren't any elements to print." << endl;
	}
    else 
    {
		DLListNode* node = tail;
		while (node != nullptr) 
        {
			cout << node->val << " ";
			node = node->prev;
		}

		cout << "\n" << endl;
	}
}

void DoublyLinkedList::printList()
{
    cout << "\033[0;33mList:\033[0m" << endl;
    if (tail == nullptr) 
    {
		cout << "There aren't any elements to print." << endl;
	}
    else 
    {
		DLListNode* node = tail;
		while (node != nullptr) 
        {
			cout << node->val << " ";
			node = node->prev;
		}

		cout << "\n" << endl;
	}
}