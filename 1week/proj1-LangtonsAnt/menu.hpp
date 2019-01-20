#ifndef MENU_H
#define MENU_H
#include <string>
using std::string;


class Menu
{
    private:
        int inputs[6];
        string prompts[6];

    public:
        void getInfo();
        bool prompt(int i);
        bool intCheck();
        bool minCheck(int input, int min);
        bool maxCheck(int input, int max);
};

#endif