#ifndef GIFT_H
#define GIFT_H
#include <iostream>
#include <ostream>
#include <vector>
#include <string.h>
#include "BToyClass.h"
using namespace std;
class Gift
{
private:
    string name, destination, personName;
    vector<unique_ptr<BToyClass>> toys;
    int toysLength = 0, id, idToys = 0;
    static int idClass;

public:
    Gift(const string _name = "undefined ", const string _destination = "undefined", const string _personName = "undefined", vector<BToyClass *> _toys = {}, int _toysLength = 0);
    Gift(const Gift &obj);
    Gift &operator=(const Gift &obj);
    friend istream &operator>>(istream &in, Gift &obj);
    friend ostream &operator<<(ostream &out, Gift &obj);
    friend bool operator==(const Gift &lhs, const Gift &rhs);
    const string getName() const;
    const string getDestination() const;
    const string getPersonName() const;
    vector<BToyClass *> getToys();
    int getToysLength();
    void setName(const string _name);
    void setDestination(const string _destination);
    void setPersonName(const string _personName);
    void setToys(const vector<BToyClass *> _toys, const int _toysLength);
    void updateGift();
    void summariseGift();

    ~Gift()
    {
    }
};
#endif