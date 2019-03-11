/********************************************************************* 
** Program name: Stack and Queue STL Containers Lab  
** Description: Declaration of menu functions. 
*********************************************************************/
#ifndef MENU_H
#define MENU_H

#include <queue>
using std::queue;

void mainMenu();
void buffer();
void printBuffer(queue<int> buffer);
void palindrome();

#endif