/********************************************************************* 
** Program: TODO: 
** Description: TODO: 
*********************************************************************/

#include <fstream>
using std::ofstream;

void output_letters(ofstream& outputFile, int* letterCount)
{
    for (int i = 0; i < 26; i++) 
    {
        char letter = (i+97);
        outputFile << letter << ": " << letterCount[i] << "\n";
    }
    outputFile.close();
}