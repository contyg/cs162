#ifndef ANT_H
#define ANT_H

class Ant
{
    private:
        char ant;
        int row;
        int col;

    public:
        Ant(int row, int col);
        ~Ant();
        void setRowColl(int r, int c);
        void move(char **board);
};

#endif