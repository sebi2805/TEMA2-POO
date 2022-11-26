#ifndef GIFT_H
#define GIFT_H
#include <iostream>
#include <ostream>
#include <string.h>
#include "ToyClass.h"
using namespace std;
class Gift
{
private:
    char *name = new char[1], *destination, *personName;
    ToyClass *toys = new ToyClass[1];
    int toysLength, id, idToys = 1;
    static int idClass;

public:
    Gift(const char *_name = "undefined", const char *_destination = "undefined", const char *_personName = "undefined", ToyClass *_toys = {}, int _toysLength = 0);
    Gift(const Gift &obj);
    Gift &operator=(const Gift &obj);
    friend istream &operator>>(istream &in, Gift &obj);
    friend ostream &operator<<(ostream &out, Gift &obj);
    friend bool operator==(const Gift &lhs, const Gift &rhs);
    char *getName() const;
    char *getDestination() const;
    char *getPersonName() const;
    ToyClass *getToys() const;
    int getToysLength();
    void setName(const char *_name);
    void setDestination(const char *_destination);
    void setPersonName(const char *_personName);
    void setToys(const ToyClass *_toys, const int _toysLength);
    void updateGift();
    void summariseGift();

    ~Gift()
    {
        delete[] name;
        delete[] destination;
        delete[] toys;
        delete[] personName;
    }
};
#endif