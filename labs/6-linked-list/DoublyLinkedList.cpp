/********************************************************************* 
** Program name: Doubly-linked List Lab  
** Description: Definition of linked list functions  
*********************************************************************/

#include "DoublyLinkedList.hpp" 
#include <iostream>

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

}

void DoublyLinkedList::deleteFirstNode()
{

}

void DoublyLinkedList::deleteLastNode()
{

}

void DoublyLinkedList::printReverseList()
{

}

void DoublyLinkedList::printList()
{

}