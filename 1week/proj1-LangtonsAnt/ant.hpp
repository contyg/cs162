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
        Ant(int *inputs);
        ~Ant();
        void makeBoard();
        void play(int turns);
        void print();
};

#endif