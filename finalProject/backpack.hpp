#ifndef BACKPACK_hpp
#define BACKPACK_hpp
#include <iostream>
#include <string>

using std::string;

class Backpack
{
private:
    bool full;
    int itemCount;
    bool trifectaNotUsed;

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
    int getItemCount();
    bool getFull();
    bool getTrifectaNotUsed();
    void setTrifectaUsed(bool val);
};

#endif