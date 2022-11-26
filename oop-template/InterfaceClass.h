#ifndef INTERFACE_CLASS
#define INTERFACE_CLASS
#include <iostream>
#include "Gift.h"
class InterfaceMenu
{
private:
    Gift *allGifts = new Gift[10];
    int i;
    int numberOfGifts = 0;

public:
    InterfaceMenu(){};
    void start();
    ~InterfaceMenu()
    {
        delete[] allGifts;
    }
};
#endif