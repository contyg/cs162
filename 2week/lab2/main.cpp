/********************************************************************* 
** Program name: TODO:
** Author: Genevieve Conty
** Date: 01/20/2019
** Description: TODO: 
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
    int* countArr = new int[26];

    string inFileName;
    ifstream inputFile;
    string outFileName;
    ofstream outputFile;

    // ask name of input file
    cout << "What is your input file name?" << endl;
    cin >> inFileName; 

    // Check if input file is valid
    inputFile.open(inFileName);
    if(!inputFile)
    {
        cout << "\033[1;31m ERROR: cannot access that file \033[0m\n";
        return -1;
    }
    count_letters(inputFile, countArr);
    
    // ask name of output file
    cout << "What is your output file name?" << endl;
    cin >> outFileName;
    
    // Check if output file is valid
    outputFile.open(outFileName);
    if(!outputFile)
    {
        cout << "\033[1;31m ERROR: cannot access that file \033[0m\n";
        return -1;
    }

    output_letters(outputFile, countArr);

    
    return 0;
}