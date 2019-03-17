//TODO: description

#ifndef SPACE_hpp
#define SPACE_hpp

class Space
{

protected:
    Space* top;
    Space* bottom;
    Space* left;
    Space* right;
    int column;
    int row;

public:
    Space();

    Space* getTop();
    Space* getBottom();
    Space* getLeft();
    Space* getRight();

    void setLinkedSpaces(Space* T, Space* B, Space* L, Space* R);
};

#endif