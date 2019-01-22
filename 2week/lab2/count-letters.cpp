/********************************************************************* 
** Program: Count Letters 
** Description: Definition for the count_letters function. Function 
**              counts frequency of each letter.
*********************************************************************/

#include <iostream>
#include <fstream>
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;


void count_letters(ifstream& inputFile, int* letterCount)
{
    char letter;
    while (inputFile >> letter) 
    {
        for (int i = 0; i < 26; i++) 
        {
            if (letter == 10) {
                letterCount = {0};
                break;
            }
            else if (letter == (i+65) || letter == (i+97))
            {   
                letterCount[i]++;
                break;
            }
        }
    }
    inputFile.close();
}