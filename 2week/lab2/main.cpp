/********************************************************************* 
** Program name: Count Letters
** Author: Genevieve Conty
** Date: 01/20/2019
** Description: Open a user-given input file, count the frequency of
**              each letter. Output the frequencies in a a user-given 
**              output file.
*********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "count-letters.hpp"
using std::ifstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;


int main() 
{	  
    int countArr[26] = {0}; 
    int* letterCount = countArr;

    string inFileName;
    ifstream inputFile;
    
    // ask name of input file
    cout << "What is your input file name?" << endl;
    cin >> inFileName;

    // Check if input file is valid
    inputFile.open(inFileName);
    if(!inputFile)
    {
        cout << "\033[1;31m ERROR: cannot access that input file \033[0m\n";
        exit(0);
    }

    count_letters(inputFile, letterCount);

    return 0;
}