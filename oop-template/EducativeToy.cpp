#include <iostream>
#include <string>
#include "EducativeToy.h"
#include "BToyClass.h"

EducativeToy::EducativeToy(const std::string _name, float _price, float _weight,
                           const std::string _category, int _age, int _id,
                           std::string abilityLearned) : BToyClass(_name, _price, _weight, _category, _age, _id),
                                                         abilityLearned(abilityLearned)
{
}
EducativeToy::EducativeToy(const EducativeToy &obj) : BToyClass(obj)
{
    abilityLearned = obj.abilityLearned;
}
const string EducativeToy::getAbilityLearned() const
{
    return abilityLearned;
};

void EducativeToy::setAbilityLearned(const string _abilityLearned)
{
    abilityLearned = _abilityLearned;
};
void EducativeToy::playSound()
{
    std::cout << "Hi! I'm " << getName() << " and I'm a educative toy." << endl;
};
bool EducativeToy::operator==(const EducativeToy &obj)
{
    return BToyClass::operator==(obj) && abilityLearned == obj.abilityLearned;
};
bool EducativeToy::operator!=(const EducativeToy &obj)
{
    return !(*this == obj);
};
EducativeToy &EducativeToy::operator=(const EducativeToy &obj)
{
    BToyClass::operator=(obj);
    abilityLearned = obj.abilityLearned;
    return *this;
};
ostream &operator<<(ostream &out, EducativeToy &obj)
{

    out << *dynamic_cast<BToyClass *>(&obj)
        << "        Abilitatea dezvoltata este: " << obj.abilityLearned << endl;
    return out;
};
istream &operator>>(istream &in, EducativeToy &obj)
{
    in >> *dynamic_cast<BToyClass *>(&obj);
    std::cout << "Introduceti abilitatea dezvoltata:" << endl;
    in.ignore();
    getline(in, obj.abilityLearned);
    return in;
};
