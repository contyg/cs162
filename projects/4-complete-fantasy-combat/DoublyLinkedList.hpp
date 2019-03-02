/********************************************************************* 
** Program name: Doubly-linked List Lab  
** Description: Declaration of linked list functions  
*********************************************************************/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include "character.hpp"

class DoublyLinkedList 
{ 

private:
    struct DLListNode {
		Character* type;
		DLListNode* prev;
		DLListNode* next;
		
		DLListNode(Character* t, DLListNode* p = nullptr, DLListNode* n = nullptr) 
        {
			type = t;
			prev = p;
			next = n;
		}
	};

    DLListNode* head;
    DLListNode* tail;

public: 
    DoublyLinkedList();
    ~DoublyLinkedList();

    void addHead(Character* type);
    void printList();
};


#endif