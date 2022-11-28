#ifndef INTERFACE_CLASS
#define INTERFACE_CLASS
#include <iostream>
#include "Gift.h"
#include <memory>
using namespace std;
class InterfaceMenu
{
private:
    vector<unique_ptr<Gift>> allGifts;
    int i;

public:
    static void printMessage();
    InterfaceMenu(){};
    void start();
    ~InterfaceMenu()
    {
    }
};
#endif