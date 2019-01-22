/********************************************************************* 
** Program: TODO: 
** Description: TODO: 
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
            if (letter == (i+65) || letter == (i+97))
            {   
                letterCount[i]++;
                break;
            }
        }
    }
    inputFile.close();
}