#ifndef GIFT_H
#define GIFT_H
#include <iostream>
#include <ostream>
#include <vector>
#include <string.h>
#include <memory>
#include "BToyClass.h"

class Gift
{
private:
    std::string name, destination, personName;
    std::vector<shared_ptr<BToyClass>> toys;
    int toysLength = 0, id, idToys = 0;
    static int idClass;

public:
    explicit Gift(const std::string _name = "undefined ",
                  const std::string _destination = "undefined", const std::string _personName = "undefined",
                  std::vector<shared_ptr<BToyClass>> _toys = {}, int _toysLength = 0);
    Gift(const Gift &obj);
    Gift &operator=(const Gift &obj);
    friend istream &operator>>(istream &in, Gift &obj);
    friend ostream &operator<<(ostream &out, Gift &obj);
    friend void updateToyHelper(istream &in, Gift &obj, bool update);
    friend bool operator==(const Gift &lhs, const Gift &rhs);
    const std::string getName() const;
    const std::string getDestination() const;
    const std::string getPersonName() const;
    const int getId() const;
    std::vector<shared_ptr<BToyClass>> getToys();
    const static int getCurrentId();
    const int getToysLength() const;
    void setName(const std::string _name);
    void setDestination(const std::string _destination);
    void setPersonName(const std::string _personName);
    void setToys(const std::vector<shared_ptr<BToyClass>> _toys, const int _toysLength);
    void updateGift();
    void setToysLength(int _toysLength);
    void summariseGift();
    ~Gift()
    {
    }
};

#endif