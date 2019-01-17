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
    setRowColl(100, 100);
    makeBoard();
    orientation = 0;
    setPosition(x, y);
    move(xCoord, yCoord, '*');
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

void Ant::setPosition(int x, int y)
{
    cout << "\033[1;34m set position \033[0m\n";

    xCoord = x;
    yCoord = y;
    
    whiteTile = true;
}

void Ant::setRowColl(int r, int c)
{
    cout << "\033[1;34m setRowColl \033[0m\n";
    row = r;
    col = c;
}

void Ant::makeBoard()
{
    cout << "\033[1;34m make board \033[0m\n"; // REMOVE:
    
    // dynamically allocate 2D array
    board = new char*[col]; // rows

    for(int n = 0; n < col; ++n)
    {
        board[n] = new char[row]; // columns
    }

    // populate board with 'white' spaces
    for(int i = 0; i < col; i++)
	{
		for(int j = 0; j < row; j++)
			board[i][j] = '-';
	}
}

void Ant::move(int x, int y, char move)
{
    
    board[y][x] = move;
    cout << "\033[1;34m move ant \033[0m\n";
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

        cout << "\033[1;31mbold orientation: "<< orientation <<"\033[0m\n";
        cout << "\033[1;31mbold white tile: "<< whiteTile <<"\033[0m\n";
        cout << "\033[1;36m " << "xCoord: " << xCoord << ", yCoord: " << yCoord << "\033[0m\n";

        board[yCoord][xCoord] = '*';
        
        print();
        i++;
    }
}