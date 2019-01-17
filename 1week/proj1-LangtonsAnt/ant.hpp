#ifndef ANT_H
#define ANT_H

enum direction {UP, RIGHT, DOWN, LEFT};

class Ant
{
    private:
        int row;
        int col;
        int xCoord;
        int yCoord;
        char **board;
        int orientation;
        bool whiteTile;

    public:
        // TODO: default constructor for random
        Ant(int x, int y);
        ~Ant();
        void makeBoard();
        void play(int turns);
        void print();
};

#endif