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
    xCoord = x;
    yCoord = y;
    row = 70;
    col = 70;
    orientation = 0;
    whiteTile = true;
    makeBoard();
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

void Ant::makeBoard()
{    
    // dynamically allocate 2D array
    board = new char*[col]; // columns

    for(int n = 0; n < col; ++n)
    {
        board[n] = new char[row]; // rows
    }

    // populate board with 'white' spaces
    for(int i = 0; i < col; i++)
	{
		for(int j = 0; j < row; j++)
			board[i][j] = '-';
	}

    // set ant
    board[yCoord][xCoord] = '*';
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
    print();

    cout << "\033[1;36m play none \033[0m\n"; // REMOVE:
    int i = 0;
    while(i < turns)
    {
        cout << "\033[1;36m play #" << i << " \033[0m\n"; // REMOVE:
        
        // change spaces black (#) / white (' ')
        if (whiteTile)
        {
            board[yCoord][xCoord] = '#';
        }
        else 
        {
            board[yCoord][xCoord] = '-';
        }
        
        // REMOVE:
        cout << "\033[1;31mbold orientation: "<< orientation <<"\033[0m\n"; 

        // change orientation
        //TODO: orientation at edge
        if (whiteTile && orientation != UP)
        {
            orientation--;
        } 
        else if (whiteTile && orientation == UP) 
        {
            orientation = LEFT;
        } 
        else if (!whiteTile && orientation == LEFT)
        {
            orientation = UP;
        }
        else 
        {
            orientation++;
        }

        // move based on orientation
        switch (orientation)
        {
            case UP:
                yCoord += 1;
                break;
            case RIGHT:
                xCoord += 1;
                break;
            case DOWN:
                yCoord -= 1;
                break;
            case LEFT:
                xCoord -= 1;
                break;
            default:
                break;
        }
        
        // change whiteTile based on next space
        if (board[yCoord][xCoord] == '#')
        {
            whiteTile = false;
        } 
        else 
        {
            whiteTile = true;
        }

        // REMOVE:
        cout << "\033[1;31mbold orientation: "<< orientation <<"\033[0m\n";
        cout << "\033[1;31mbold white tile: "<< whiteTile <<"\033[0m\n";
        cout << "\033[1;36m " << "xCoord: " << xCoord << ", yCoord: " << yCoord << "\033[0m\n";

        board[yCoord][xCoord] = '*';
        
        print();
        i++;
    }
}