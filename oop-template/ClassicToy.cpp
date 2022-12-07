#include <iostream>
#include <string>
#include "ClassicToy.h"
#include "BToyClass.h"
#include "BPlay.h"

ClassicToy::ClassicToy(const std::string _name, float _price, float _weight,
                       const std::string _category, int _age, int _id,
                       std::string material, string color) : BToyClass(_name, _price, _weight, _category, _age, _id),
                                                             material(material), color(color)
{
}
ClassicToy::ClassicToy(const ClassicToy &obj) : BToyClass(obj)
{
    material = obj.material;
    color = obj.color;
}
const std::string ClassicToy::getMaterial() const
{
    return material;
};
const std::string ClassicToy::getColor() const
{
    return color;
};
void ClassicToy::setMaterial(const std::string _material)
{
    material = _material;
};
void ClassicToy::setColor(const std::string _color)
{
    color = _color;
};
bool ClassicToy::operator==(const ClassicToy &obj)
{
    return BToyClass::operator==(obj) && material == obj.material && color == obj.color;
};
bool ClassicToy::operator!=(const ClassicToy &obj)
{
    return !(*this == obj);
};
ClassicToy &ClassicToy::operator=(const ClassicToy &obj)
{
    BToyClass::operator=(obj);
    material = obj.material;
    color = obj.color;
    return *this;
};
ostream &operator<<(ostream &out, ClassicToy &obj)
{

    out << *(dynamic_cast<BToyClass *>(&obj))
        << "        Material este: " << obj.material << " si culoarea: " << obj.color << endl;
    return out;
};
void ClassicToy::playSound()
{
    std::cout << "Hi! I'm " << getName() << " and I'm a classic toy." << endl;
};
istream &operator>>(istream &in, ClassicToy &obj)
{
    in >> static_cast<BToyClass &>(obj);
    std::cout << "Introduceti numele materialului:" << endl;
    in.ignore();
    getline(in, obj.material);
    std::cout << "Introduceti culoarea:" << endl;
    getline(in, obj.color);
    return in;
};
