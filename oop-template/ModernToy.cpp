#include <iostream>
#include <string>
#include "ModernToy.h"
#include "ElectronicToy.h"
#include "EducativeToy.h"
using namespace std;
ModernToy::ModernToy(const string _name, float _price, float _weight,
                     const string _category, int _age, int _id,
                     string brand, int _numberBatteries, string abilityLearned) : ElectronicToy(_name, _price, _weight, _category, _age, _id, _numberBatteries),
                                                                                  EducativeToy(_name, _price, _weight, _category, _age, _id, abilityLearned), brand(brand)
{
}
ModernToy::ModernToy(const ModernToy &obj) : ElectronicToy(obj), EducativeToy(obj)
{
    brand = obj.brand;
}
const string ModernToy::getAbilityLearned() const
{
    return brand;
};

void ModernToy::setAbilityLearned(const string _brand)
{
    brand = _brand;
};

bool ModernToy::operator==(const ModernToy &obj)
{
    return ElectronicToy::operator==(obj) && EducativeToy::operator==(obj) && brand == obj.brand;
};
bool ModernToy::operator!=(const ModernToy &obj)
{
    return !(*this == obj);
};
ModernToy &ModernToy::operator=(const ModernToy &obj)
{
    ElectronicToy::operator=(obj);
    EducativeToy::operator=(obj);
    brand = obj.brand;
    return *this;
};
ostream &operator<<(ostream &out, ModernToy &obj)
{
    out << "ModernToy" << endl;
    out << *dynamic_cast<ElectronicToy *>(&obj) << *dynamic_cast<EducativeToy *>(&obj)
        << "        Brandul este: " << obj.brand << endl;
    return out;
};
istream &operator>>(istream &in, ModernToy &obj)
{

    in >> *dynamic_cast<ElectronicToy *>(&obj) >> *dynamic_cast<EducativeToy *>(&obj);
    cout << "Introduceti numele brandului:" << endl;
    in >> obj.brand;

    return in;
};
