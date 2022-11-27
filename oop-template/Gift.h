#ifndef GIFT_H
#define GIFT_H
#include <iostream>
#include <ostream>
#include <vector>
#include <string.h>
#include <memory>
#include "BToyClass.h"
using namespace std;
class Gift
{
private:
    string name, destination, personName;
    vector<shared_ptr<BToyClass>> toys;
    int toysLength = 0, id, idToys = 0;
    static int idClass;

public:
    explicit Gift(const string _name = "undefined ",
                  const string _destination = "undefined", const string _personName = "undefined",
                  vector<shared_ptr<BToyClass>> _toys = {}, int _toysLength = 0);
    Gift(const Gift &obj);
    Gift &operator=(const Gift &obj);
    friend istream &operator>>(istream &in, Gift &obj);
    friend ostream &operator<<(ostream &out, Gift &obj);
    friend void updateToyHelper(istream &in, Gift &obj);
    friend bool operator==(const Gift &lhs, const Gift &rhs);
    const string getName() const;
    const string getDestination() const;
    const string getPersonName() const;
    const int getId() const;
    vector<shared_ptr<BToyClass>> getToys();
    int getToysLength() const;
    void setName(const string _name);
    void setDestination(const string _destination);
    void setPersonName(const string _personName);
    void setToys(const vector<shared_ptr<BToyClass>> _toys, const int _toysLength);
    void updateGift();
    void setToysLength(int _toysLength);
    void summariseGift();
    ~Gift()
    {
    }
};

#endif