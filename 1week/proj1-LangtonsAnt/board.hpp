
#ifndef BOARD_H
#define BOARD_H

class Board
{
    private:
        char **board;
        int row;
        int col;

    public:
        Board(int row, int col);
        ~Board();
        // TODO: default constructor for random
        void setRowColl(int r, int c);
        void play(int turns);
        void print();
};

#endif