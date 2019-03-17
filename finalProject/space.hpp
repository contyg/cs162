//TODO: description

#ifndef SPACE_hpp
#define SPACE_hpp

#include <string>
using std::string;

class Space
{

protected:
    Space* top;
    Space* bottom;
    Space* left;
    Space* right;
    int column;
    int row;
    string type;

public:
    Space();

    //getters
    Space* getTop();
    Space* getBottom();
    Space* getLeft();
    Space* getRight();
    string getType();

    //setters
    void setType(string t);
    void setLinkedSpaces(Space* T, Space* B, Space* L, Space* R);

    //virtual functions
    virtual int healthPenalty();
};

#endif