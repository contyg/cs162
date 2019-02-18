/********************************************************************* 
** Program name: Doubly-linked List Lab  
** Description: Definition of linked list functions  
*********************************************************************/

#include "validate.hpp"
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

void DoublyLinkedList::addHead()
{
    double testInput;

    cout << "\033[0;36m Please enter an integer \033[0m\n";

    cin >> testInput;

    if (!isInteger(testInput))
    {
        addHead();
    }

    int newHead = (int)testInput;

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

void DoublyLinkedList::addTail()
{
    double testInput;

    cout << "\033[0;36m Please enter an integer \033[0m\n";

    cin >> testInput;

    if (!isInteger(testInput))
    {
        addTail();
    }

    int newTail = (int)testInput;

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
		cout << "\033[0;31There aren't any elements to delete.\033[0m" << endl;
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
		cout << "\033[0;31There aren't any elements to delete.\033[0m" << endl;
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
    cout << "\033[1;33mReversed List:\033[0m" << endl;
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
    cout << "\033[1;33mList:\033[0m" << endl;
    if (tail == nullptr) 
    {
		cout << "There aren't any elements to print." << endl;
	}
    else 
    {
		DLListNode* node = head;
		while (node != nullptr) 
        {
			cout << node->val << " ";
			node = node->next;
		}

		cout << "\n" << endl;
	}
}