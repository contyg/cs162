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
    antCol = x;
    antRow = y;
    row = 10;
    col = 10;
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

    cout << "\033[1;34m delete board \033[0m\n"; // REMOVE:

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
			board[i][j] = '-';
	}

    // set ant
    board[antRow][antCol] = '*';
}

void Ant::print()
{
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
    if(turns <= 0)
    {
        return;
    }

    cout << "\033[1;36m play #" << turns << " \033[0m\n"; // REMOVE:
    
    // change spaces black (#) / white (' ')
    if (whiteTile)
    {
        board[antRow][antCol] = '#';
    }
    else 
    {
        board[antRow][antCol] = '-';
    }

    // REMOVE:
    cout << "\033[1;31mbold 1orientation: "<< orientation <<"\033[0m\n"; 

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
            if ((antRow-1) < 0) {
                play(turns);
                return;
            }
            else {
                antRow -= 1;
            }
            break;
        case RIGHT:
            if ((antCol+1) >= col) { 
                play(turns);
                return;
            }
            else {
                antCol += 1;
            }
            break;
        case DOWN:
            if ((antRow+1) >= row) { 
                play(turns);
                return;
            }
            else {
                antRow += 1;
            }
            break;
        case LEFT:
            if ((antCol-1) < 0) { 
                play(turns);
                return;
            }
            else {
                antCol -= 1;
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

    // REMOVE:
    cout << "\033[1;31mbold 2orientation: "<< orientation <<"\033[0m\n";
    cout << "\033[1;31mbold white tile: "<< whiteTile <<"\033[0m\n";
    cout << "\033[1;36m " << "antCol: " << antCol << ", antRow: " << antRow << "\033[0m\n";

    board[antRow][antCol] = '*';
    
    print();
    play(--turns);
}