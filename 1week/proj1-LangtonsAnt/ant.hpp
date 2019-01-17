#ifndef ANT_H
#define ANT_H

enum direction {UP, DOWN, LEFT, RIGHT};

class Ant
{
    private:
        char ant;
        int row;
        int col;
        int xCoord;
        int yCoord;
        char **board;
        direction orientation;


    public:
        // TODO: default constructor for random
        Ant(int x, int y);
        ~Ant();
        void setPosition(int x, int y);
        void setRowColl(int r, int c);
        void makeBoard(int row, int col);
        void play(int turns);
        void move(int x, int y, char move);
        void print();
};

#endif