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
#include "output-letters.hpp"
using std::ifstream;
using std::ofstream;
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
    count_letters(inputFile, letterCount);
    
    ofstream outputFile;
    output_letters(outputFile, letterCount);

    return 0;
}