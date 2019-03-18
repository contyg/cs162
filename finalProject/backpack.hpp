#ifndef BACKPACK_hpp
#define BACKPACK_hpp

class Backpack
{
private:
    bool full;

public:
    Backpack();
    ~Backpack();

    void addItem();
    void removeItem();
    void search();
    void printContents();
};

#endif