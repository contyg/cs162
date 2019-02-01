/********************************************************************* 
** Program: Zoo Tycoon
** Description: Declaration for input validiation functions. Includes
**              integer check, isAbove check, and is between check. 
*********************************************************************/

#ifndef VALIDATE_H
#define VALIDATE_H

bool isInteger(double testInput);
bool isAbove(int input, int min);
bool isBetween(int input, int min, int max);

#endif