/********************************************************************* 
** Program name: Doubly-linked queue Lab  
** Description: Definition of menu function. Routes user to corrent 
**              function and action.
*********************************************************************/

#include "validate.hpp"
#include "queue.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int addBackMenu()
{
    double testInput;

    cout << "\033[0;36m Please enter an integer \033[0m\n";

    cin >> testInput;

    if (!isInteger(testInput))
    {
        addBackMenu(); 
    }

    int newBack = (int)testInput;

    return newBack;
}

void menu()
{
    Queue queue;
    bool keepPlaying = true;
    
    cout << "\033[1;36mLET'S PLAY WITH QUEUES!! \033[0m" << endl;

    while (keepPlaying)
    {
        double testInput;

        cout << "\033[0;36mChoose an option: \n"
        << "    1: Enter a value to be added to the back of queue \n"
        << "    2: Display first node (front) value \n"
        << "    3: Remove first node (front) value \n"
        << "    4: Display the queue contents \n"
        << "    5: Exit \n\033[0m" << endl;


        cin >> testInput;

        if (!isInteger(testInput))
        {
            break; // re-trigger menu if input invalid
        }

        int input = (int)testInput;

        if (!isBetween(input, 0, 6))
        {
            break; // re-trigger menu if input invalid
        }

        switch (input)
        {
            case 1:
            {
                int val = addBackMenu();
                queue.addBack(val);
                break;
            }
            case 2:
                if (queue.isEmpty())
                {
                    cout << "There isn't a front because the queue is empty.\n" << endl;
                }
                else
                {
                    cout << queue.getFront() << endl;
                }
                break;
            case 3:
                if (queue.isEmpty())
                {
                    cout << "There aren't any elements to delete.\n" << endl;
                }
                else
                {
                    queue.removeFront();
                }
                break;
            case 4:
                if (queue.isEmpty())
                {
                    cout << "There aren't any elements to print. \n" << endl;
                }
                else
                {
                    queue.printQueue();
                }
                break;
            default:
                keepPlaying = false;
                cout << "\033[1;36mBYEEE! \033[0m\n";
                break;
        }
    } 
}
