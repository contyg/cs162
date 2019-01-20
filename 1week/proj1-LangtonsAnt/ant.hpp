#ifndef ANT_H
#define ANT_H

enum direction {UP, RIGHT, DOWN, LEFT};

class Ant
{
    private:
        int row;
        int col;
        int antCol;
        int antRow;
        char **board;
        int orientation;
        bool whiteTile;

    public:
        // TODO: default constructor for random
        Ant(int r, int c);
        ~Ant();
        void makeBoard();
        void play(int turns);
        void print();
        // void randomAntStart();
};

#endif