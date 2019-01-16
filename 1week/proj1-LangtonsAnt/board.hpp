
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
        void setRowColl(int r, int c);
        void play(int turns);
        void print();
};

#endif