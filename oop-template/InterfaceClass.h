#ifndef INTERFACE_CLASS
#define INTERFACE_CLASS
#include <iostream>
#include "Gift.h"
class InterfaceMenu
{
private:
    vector<Gift> allGifts;
    int i;

public:
    InterfaceMenu(){};
    void start();
    ~InterfaceMenu()
    {
    }
};
#endif