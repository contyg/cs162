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
    // menu and validation
    double testInput;

    cout << "\033[0;36m Please enter an integer \033[0m\n";

    cin >> testInput;

    if (!isInteger(testInput))
    {
        addHead();
    }

    int newHead = (int)testInput;

    if (head == nullptr) // check if list is empty
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
    // menu and validation
    double testInput;

    cout << "\033[0;36m Please enter an integer \033[0m\n";

    cin >> testInput;

    if (!isInteger(testInput))
    {
        addTail();
    }

    int newTail = (int)testInput;

    if (tail == nullptr) // check if list is empty
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
    if (head == nullptr)  // check if list is empty
    {
		cout << "There aren't any elements to delete.\n" << endl;
	} 
    else if (head->next == nullptr) // check if list has 1 element
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
    if (tail == nullptr) // check if list is empty
    {
		cout << "There aren't any elements to delete.\n" << endl;
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
    if (tail == nullptr) // check if list is empty
    {
		cout << "There aren't any elements to print. \n" << endl;
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
    if (tail == nullptr) // check if list is empty
    {
		cout << "There aren't any elements to print. \n" << endl;
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

void DoublyLinkedList::printHeadValue()
{
    cout << "\033[1;33mHead Value:\033[0m" << endl;

    if (head == nullptr)
    {
        cout << "There aren't any elements to print. \n" << endl;
    }
    else
    {
        cout << head->val << endl;
    }
}

void DoublyLinkedList::printTailValue()
{
    cout << "\033[1;33mTail Value:\033[0m" << endl;

    if (tail == nullptr)
    {
        cout << "There aren't any elements to print. \n" << endl;
    }
    else
    {
        cout << tail->val << endl;
    }
}