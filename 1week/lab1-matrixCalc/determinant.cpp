/********************************************************************* 
** Program name: Matrix Calculator
** Author: Genevieve Conty
** Date: 01/13/2019
** Description: A matrix calculator for 2x2 and 3x3 matrices 
*********************************************************************/

#include "determinant.hpp"

int determinant(int **matrix, int matrixSize)
{
    int determinant = 0;
    // 2x2 formula: ad-bc
    if (matrixSize == 2) {
        determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    } 
    // 3x3 formula: a(ei-fh)-b(di-fg)-c(dh-eg)
    else {
        int det1 = (matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]);
        int det2 = (matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]);
        int det3 = (matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]);
        determinant =  (matrix[0][0] * det1) - (matrix[0][1] * det2) - (matrix[0][2] * det3);
    }
    return determinant;
};