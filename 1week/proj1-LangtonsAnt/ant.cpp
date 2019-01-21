#include <iostream>
#include "ant.hpp"
#include "menu.hpp"

using std::cout;
using std::cin;
using std::endl;

// place ant based on user input
Ant::Ant(int * inputs)
{
    
    row = inputs[0];
    col = inputs[1];
    antRow = inputs[2];
    antCol = inputs[3];
    orientation = 0;
    whiteTile = true;
    makeBoard();
}

Ant::~Ant() 
{
    // free matrix memory
    for (int i = 0; i < col; ++i)
    {
        delete[] board[i];
    }
    delete[] board;
}

void Ant::makeBoard()
{    
    // dynamically allocate 2D array
    board = new char*[row]; 
    for(int n = 0; n < row; ++n)
    {
        board[n] = new char[col]; 
    }

    // populate board with 'white' spaces
    for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
	}

    // set ant
    board[antRow][antCol] = '*';
    print();
}

void Ant::print()
{
    // TODO: do space instead of -
    for(int i = 0; i < row; i++)
	{

		for(int j = 0; j < col; j++)
        {
            if (board[i][j] != '*') 
            {
                cout << board[i][j];
            } 
            else 
            {
                cout << "\033[1;31m"<< board[i][j] <<"\033[0m"; 
            }
        }
        
        cout << endl;
	}
}

void Ant::play(int turns) 
{
    if(turns <= 0)
    {
        return;
    }
    
    // change spaces black (#) / white (' ')
    if (whiteTile)
    {
        board[antRow][antCol] = '#';
    }
    else 
    {
        board[antRow][antCol] = ' ';
    }

    // change orientation
    if (whiteTile && orientation != LEFT)
    {
        orientation++;
    } 
    else if (whiteTile && orientation == LEFT) 
    {
        orientation = UP;
    } 
    else if (!whiteTile && orientation != UP)
    {
        orientation--;
    }
    else 
    {
        orientation = LEFT;
    }

    // move based on orientation
    switch (orientation)
    {
        case UP:
            antRow--;
            if (antRow < 0) 
            {
                antRow = (row-1);
            }
            break;
        case RIGHT:
            antCol++;
            if (antCol >= (col-1)) 
            { 
                antCol = 0;
            }
            break;
        case DOWN:
            antRow++;
            if (antRow >= (row-1)) 
            { 
                antRow = 0;
            }
            break;
        case LEFT:
            antCol--;
            if (antCol < 0) 
            { 
                antCol = (col-1);
            }
            break;
        default:
            break;
    }
    // change whiteTile based on next space
    if (board[antRow][antCol] == '#')
    {
        whiteTile = false;
    } 
    else 
    {
        whiteTile = true;
    } 

    board[antRow][antCol] = '*';

    print();
    play(--turns);
}