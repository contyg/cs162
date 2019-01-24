/********************************************************************* 
** Program name: Matrix Calculator
** Author: Genevieve Conty
** Date: 01/13/2019
** Description: A matrix calculator for 2x2 and 3x3 matrices 
*********************************************************************/
#include <iostream>
#include "readMatrix.hpp"
#include "determinant.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() 
{	
    int matrixSize = 0;
    cout << "The size your matrix can be 2x2 or 3x3. Enter 2 or 3 to choose." << endl;
    cin >> matrixSize;

    // dynamically allocate 2D array
    int** matrix = new int*[matrixSize]; // rows
    for(int i = 0; i < matrixSize; ++i)
    {
        matrix[i] = new int[matrixSize]; // columns
    }
        
    // get values from user
    readMatrix(matrix, matrixSize);

    // display matirx in block format
    cout << "Your matrix: " << endl;
	for(int row = 0; row < matrixSize; row++)
	{
		for(int col = 0; col < matrixSize; col++)
		{
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}

    // calculate and display determinant
    cout << "determinant: "<< determinant(matrix, matrixSize) << endl;

    // free matrix memory
    for (int i = 0; i < matrixSize; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

