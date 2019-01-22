/********************************************************************* 
** Program: Count Letters 
** Description: Declaration for the count_letters function. Function 
**              counts frequency of each letter. 
** Inputs: Reference to an intput file, pointer to int array (letter 
**          frequencies)
*********************************************************************/

#ifndef COUNT_FUNCTION_H
#define COUNT_FUNCTION_H
#include <fstream>
using std::ifstream;

void count_letters(ifstream&, int*);

#endif 