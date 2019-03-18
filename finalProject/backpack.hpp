#ifndef BACKPACK_hpp
#define BACKPACK_hpp
#include <iostream>
#include <string>

using std::string;

class Backpack
{
private:
    bool full;
    struct Item {
		string val;
		Item* prev;
		Item* next;
		
		Item(string v, Item* p = nullptr, Item* n = nullptr) 
        {
			val = v;
			prev = p;
			next = n;
		}
	};

    Item* head;
    Item* tail;

public:
    Backpack();
    ~Backpack();

    void addItem(string item);
    void printContents();
};

#endif