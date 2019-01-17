#include <iostream>
#include "ant.hpp"

using std::cout;
using std::cin;
using std::endl;

// place ant randomly
// Ant::Ant()
// {
//     //TODO: position ant randomly on board
//     setPosition(0, 0);
//     board.move(0, 0, '*');
// }

// place ant based on user input
Ant::Ant(int x, int y)
{
    setRowColl(70, 70);
    makeBoard(70, 70);

    setPosition(x, y);
    move(x, y, '*');
}

Ant::~Ant() 
{
    cout << "\033[1;34m delete board \033[0m\n"; // REMOVE:
    
    // free matrix memory
    for (int i = 0; i < row; ++i)
    {
        delete[] board[i];
    }
    delete[] board;
}

void Ant::setPosition(int r, int c)
{
    row = r;
    col = c;
    orientation = UP;
}

void Ant::setRowColl(int r, int c)
{
    cout << "\033[1;34m setRowColl \033[0m\n";
    row = r;
    col = c;
}

void Ant::makeBoard(int row, int col)
{
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
}

void Ant::move(int x, int y, char move)
{
    
    board[x][y] = move;
    cout << "\033[1;34m move ant \033[0m\n";
}

void Ant::print()
{
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

void Ant::play(int turns)
{
    int i = 0;
    while(i < turns)
    {
        cout << "\033[1;36m play #" << i << " \033[0m\n"; // REMOVE:
        //TODO: black white logic
        //TODO: ant at edge
        switch (orientation)
        {
            case UP:
                break;
            case DOWN:
                break;
            case RIGHT:
                break;
            case LEFT:
                break;
            default:
                break;
        }
        print();
        i++;
    }
}