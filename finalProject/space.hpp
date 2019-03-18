//TODO: description

#ifndef SPACE_hpp
#define SPACE_hpp

#include <string>
using std::string;

class Space
{

protected:
    Space* up;
    Space* down;
    Space* left;
    Space* right;
    int column;
    int row;
    string type;

public:
    Space();

    //getters
    Space* getUp();
    Space* getDown();
    Space* getLeft();
    Space* getRight();
    string getType();

    //setters
    void setType(string t);
    void setLinkedSpaces(Space* U, Space* D, Space* L, Space* R);

    //virtual functions
    virtual int healthPenalty();
};

#endif