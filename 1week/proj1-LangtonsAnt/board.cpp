#include "board.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Board::Board(int row, int col) 
{
    setRowColl(row, col);
    
    // dynamically allocate 2D array
    board = new char*[row]; // rows

    for(int n = 0; n < row; ++n)
    {
        board[n] = new char[col]; // columns
    }

    // populate board with 'white' spaces
    for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			board[i][j] = '#';
	}
};

Board::~Board() 
{
    cout << "DELETE BOARD" << endl; // REMOVE:
    // free matrix memory
    for (int i = 0; i < row; ++i)
    {
        delete[] board[i];
    }
    delete[] board;
}

void Board::setRowColl(int r, int c)
{
    row = r;
    col = c;
}

void Board::print()
{
    // REMOVE:
    cout << "print; " << "row: " << row << ", col: " << col << endl;

    for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
        {
            cout << board[i][j];
        }
        
        cout << endl;
	}
}

void Board::play(int turns)
{
    int i = 0;
    while(i < turns)
    {
        cout << "play 1: " << i << endl;
        // TODO: black/white logic
        print();
        i++;
    }
}