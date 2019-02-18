/********************************************************************* 
** Program name: Doubly-linked List Lab  
** Description: Definition of menu function. Routes user to corrent 
**              function and action.
*********************************************************************/

#include "validate.hpp"
#include "DoublyLinkedList.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void menu()
{
    DoublyLinkedList list;
    bool keepPlaying = true;
    
    cout << "\033[1;36mLET'S LINK SOME LISTS!! \033[0m" << endl;
    cout << "(EC task 1 completed) \n" << endl; 

    while (keepPlaying)
    {
        double testInput;

        cout << "\033[0;36mChoose an option: \n"
        << "    1: Add a new node to the head \n"
        << "    2: Add a new node to the tail \n"
        << "    3: Delete from head \n"
        << "    4: Delete from tail \n"
        << "    5: Traverse the list reversely \n"
        << "    6: Print head value \n"
        << "    7: Print tail value \n"
        << "    8: Exit \n\033[0m" << endl;


        cin >> testInput;

        if (!isInteger(testInput))
        {
            menu(); // re-trigger menu if input invalid
        }

        int input = (int)testInput;

        if (!isBetween(input, 0, 9))
        {
            menu(); // re-trigger menu if input invalid
        }

        switch (input)
        {
            case 1:
                list.addHead();
                list.printList();
                break;
            case 2:
                list.addTail();
                list.printList();
                break;
            case 3:
                list.deleteFirstNode();
                list.printList();
                break;
            case 4:
                list.deleteLastNode();
                list.printList();
                break;
            case 5:
                list.printReverseList();
                break;
            case 6: 
                list.printHeadValue();
                break;
            case 7:
                list.printTailValue();
                break;
            default:
                keepPlaying = false;
                cout << "\033[1;36mBYEEE! \033[0m\n";
                break;
        }
    } 
}
