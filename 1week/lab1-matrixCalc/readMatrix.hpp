/********************************************************************* 
** Program name: Matrix Calculator
** Author: Genevieve Conty
** Date: 01/13/2019
** Description: A matrix calculator for 2x2 and 3x3 matrices 
*********************************************************************/
#include <iostream>
// #include "readMatrix.hpp"
using std::cout;
using std::cin;
using std::endl;

void readMatrix(int **matrix, int matrixSize)
{
    for(int row = 0; row < matrixSize; row++)
	{
		for(int col = 0; col < matrixSize; col++)
		{
			cout << "Enter an interger for position [" << row << "][" << col << "]:" << endl;
            cin >> matrix[row][col];
            // cout << endl;
		}
	}
}