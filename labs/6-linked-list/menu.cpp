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
    
    cout << "\033[1;36mLet's link some lists! \033[0m\n";

    while (keepPlaying)
    {
        double testInput;

        cout << "\033[0;36mChoose an option: \n"
        << "    1: Add a new node to the head \n"
        << "    2: Add a new node to the tail \n"
        << "    3: Delete from head \n"
        << "    4: Delete from tail \n"
        << "    5: Traverse the list reversely \n"
        << "    6: Exit \n\033[0m" << endl;


        cin >> testInput;

        if (!isInteger(testInput))
        {
            menu(); // re-trigger menu if input invalid
        }

        int input = (int)testInput;

        if (!isBetween(input, 0, 7))
        {
            menu();
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
            default:
                keepPlaying = false;
                break;
        }
    } 
}
