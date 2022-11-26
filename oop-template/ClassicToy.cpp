#include <iostream>
#include <string>
#include "ClassicToy.h"
#include "BToyClass.h"
using namespace std;
ClassicToy::ClassicToy(const string _name, float _price, float _weight,
                       const string _category, int _age, int _id,
                       string material, string color) : BToyClass(_name, _price, _weight, _category, _age, _id),
                                                        material(material), color(color)
{
}
ClassicToy::ClassicToy(const ClassicToy &obj) : BToyClass(obj)
{
    material = obj.material;
    color = obj.color;
}
const string ClassicToy::getMaterial() const
{
    return material;
};
const string ClassicToy::getColor() const
{
    return color;
};
void ClassicToy::setMaterial(const string _material)
{
    material = _material;
};
void ClassicToy::setColor(const string _color)
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
    out << static_cast<BToyClass &>(obj)
        << "        Material este: " << obj.material << " si culoarea: " << obj.color << endl;
    return out;
};
istream &operator>>(istream &in, ClassicToy &obj)
{
    in >> static_cast<BToyClass &>(obj);
    cout << "Introduceti numele materialului:" << endl;
    in.ignore();
    getline(in, obj.material);
    cout << "Introduceti culoarea:" << endl;
    getline(in, obj.color);
    cout << obj.color;
    return in;
};
