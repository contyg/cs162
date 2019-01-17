#include "board.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Board::Board(int row, int col) 
{
    setRowColl(row, col);
    cout << "\033[1;34m make board \033[0m\n"; // REMOVE:
    
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
			board[i][j] = '-';
	}
};

Board::~Board() 
{
    cout << "\033[1;34m delete board \033[0m\n"; // REMOVE:
    
    // free matrix memory
    for (int i = 0; i < row; ++i)
    {
        delete[] board[i];
    }
    delete[] board;
}

void Board::setRowColl(int r, int c)
{
    cout << "\033[1;34m setRowColl \033[0m\n";
    row = r;
    col = c;
}

void Board::print()
{
    // REMOVE:
    cout << "\033[1;34m print board \033[0m\n";
    cout << "\033[1;36m " << "row: " << row << ", col: " << col << "\033[0m\n";

    for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
        {
            cout << board[i][j];
        }
        
        cout << endl;
	}
}

void Board::move(int row, int col, char move)
{
    cout << "\033[1;34m move board \033[0m\n";
    board[row][col] = move;
}

void Board::play(int turns)
{
    int i = 0;
    while(i < turns)
    {
        cout << "\033[1;36m play #" << i << " \033[0m\n"; // REMOVE:
        // TODO: black/white logic
        print();
        i++;
    }
}