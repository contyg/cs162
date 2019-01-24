/********************************************************************* 
** Program: Count Letters 
** Description: Declaration for the output_letters function. Outputs
**              frequency of each letter to user-given output file.
** Inputs: Reference to an output file, pointer to int array (letter 
**          frequencies)
*********************************************************************/ 

#ifndef OUTPUT_LETTERS_H
#define OUTPUT_LETTERS_H
#include <fstream>
using std::ofstream;

void output_letters(ofstream&, int*);

#endif