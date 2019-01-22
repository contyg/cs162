/********************************************************************* 
** Program: Count Letters
** Description: Definition for the output_letters function. Outputs
**              frequency of each letter to user-given output file.
** Inputs: Reference to an output file, pointer to int array (letter 
**          frequencies)
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using std::ofstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;

void output_letters(ofstream& outputFile, int* letterCount)
{
    string outFileName;

    // ask name of output file
    cout << "What is your output file name?" << endl;
    cin >> outFileName;

    // Check if output file is valid
    outputFile.open(outFileName);

    for (int i = 0; i < 26; i++) 
    {
        char letter = (i+97);
        outputFile << letter << ": " << letterCount[i] << "\n";
    }
    outputFile.close();
}