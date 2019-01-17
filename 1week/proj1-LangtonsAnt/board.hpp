
#ifndef BOARD_H
#define BOARD_H
// #include "ant.hpp"

class Board
{
    private:
        char **board;
        int row;
        int col;

    public:
        // TODO: default constructor (random)
        Board(int row = 10, int col = 10);
        ~Board();
        void setRowColl(int r, int c);
        void play(int turns);
        void move(int row, int col, char move);
        void print();
};

#endif