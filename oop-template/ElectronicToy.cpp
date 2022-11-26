#include <iostream>
#include <string>
#include "ElectronicToy.h"
#include "BToyClass.h"
using namespace std;
ElectronicToy::ElectronicToy(const string _name, float _price, float _weight,
                             const string _category, int _age, int _id,
                             int numberBatteries) : BToyClass(_name, _price, _weight, _category, _age, _id),
                                                    numberBaterries(numberBaterries)
{
}
ElectronicToy::ElectronicToy(const ElectronicToy &obj) : BToyClass(obj)
{
    numberBaterries = obj.numberBaterries;
}
const int ElectronicToy::getNumberBatteries() const
{
    return numberBaterries;
    ;
};

void ElectronicToy::setNumberBatteries(const int _numberBatteries)
{
    numberBaterries = _numberBatteries;
};

bool ElectronicToy::operator==(const ElectronicToy &obj)
{
    return BToyClass::operator==(obj) && numberBaterries == obj.numberBaterries;
};
bool ElectronicToy::operator!=(const ElectronicToy &obj)
{
    return !(*this == obj);
};
ElectronicToy &ElectronicToy::operator=(const ElectronicToy &obj)
{
    BToyClass::operator=(obj);
    numberBaterries = obj.numberBaterries;
    return *this;
};
ostream &operator<<(ostream &out, const ElectronicToy &obj)
{
    out << static_cast<BToyClass>(obj)
        << "        Numarul de baterii este: " << obj.numberBaterries << endl;
    return out;
};
istream &operator>>(istream &in, ElectronicToy &obj)
{
    in >> static_cast<BToyClass &>(obj);
    cout << "Introduceti numele materialului:" << endl;
    in >> obj.numberBaterries;

    return in;
};
