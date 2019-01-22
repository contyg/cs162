/********************************************************************* 
** Program: Count Letters 
** Description: Definition for the count_letters function. Function 
**              counts frequency of each letter.
** Inputs: Reference to an intput file, pointer to int array (letter 
**          frequencies)
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "output-letters.hpp"
using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;


void count_letters(ifstream& inputFile, int* letterCount)
{
    string paragraph;

    while (getline(inputFile, paragraph)) 
    {
        char letter;
        int n = 0;
        while (n < paragraph.length()) 
        {
            for (int i = 0; i < 26; i++) 
            {
                if (paragraph[n] == (i+65) || paragraph[n] == (i+97))
                {   
                    letterCount[i]++;
                    break;
                }
            }
            n++;
        }

        ofstream outputFile;
        output_letters(outputFile, letterCount);

        // clear array
        for (int i = 0; i < 26; i++) {
            letterCount[i] = 0;
        }
    }

    inputFile.close();
}