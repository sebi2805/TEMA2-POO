#include <iostream>
#include <string>
#include "BToyClass.h"
using namespace std;
BToyClass::BToyClass(const string _name, float _price, float _weight, const string _category, int _age, int _id)
    : category(_category), name(_name), price(_price), weight(_weight), age(_age), id(_id)
{
}
BToyClass::BToyClass(const BToyClass &obj)
    : name(obj.name), category(obj.category), price(obj.price),
      weight(obj.weight), age(obj.age), id(obj.id)
{
}
BToyClass &BToyClass::operator=(const BToyClass &obj)
{

    category = obj.category;
    name = obj.name;
    price = obj.price;
    weight = obj.weight;
    age = obj.age;
    id = obj.id;
    return *this;
};
bool BToyClass::operator==(const BToyClass &obj)
{
    bool res = (age == obj.age) && price == obj.price && weight == obj.weight && (!name.compare(obj.name)) && (!category.compare(obj.category));
    return res;
};
bool BToyClass::operator!=(const BToyClass &obj)

{
    bool res = !(*this == obj);
    return res; // !(*this == rhs)
};
ostream &operator<<(ostream &out, BToyClass &obj)
{
    string objName = typeid(obj).name();

    out << "    Id: " << obj.id << ". Numele jucariei este: " << obj.name << " cu pretul de " << obj.price << " si greutate de " << obj.weight << endl;

    return out;
};
istream &operator>>(istream &in, BToyClass &obj)
{

    cout << "Introduceti noul nume" << endl;
    in.ignore();
    getline(in, obj.name);
    cout << "Introduceti pretul jucariei.\n";
    in >> obj.price;
    cout << "Introduceti greutate.\n";
    in >> obj.weight;
    cout << "Introduceti categoria\n";
    in.ignore();
    getline(in, obj.category);
    cout << "Introduceti varsta recomandata.\n";
    in >> obj.age;
    return in;
}
const string BToyClass::getName() const
{
    return name;
};
float BToyClass::getPrice()
{
    return price;
}
float BToyClass::getWeight()
{
    return weight;
}
int BToyClass::getAge()
{
    return age;
};
const string BToyClass::getCategory() const
{
    return category;
};
void BToyClass::setName(const string _name)
{
    name = _name;
};
void BToyClass::setCategory(const string _category)
{
    category = _category;
}
void BToyClass::setPrice(float _price)
{
    price = _price;
};
void BToyClass::setWeight(float _weight)
{
    weight = _weight;
};
void BToyClass::print()
{
    cout << *this;
};
void BToyClass::setAge(float _age) { age = _age; };

void BToyClass::updateToy()
{
    int j;
    do
    {
        cout << "Ce parametru al jucariei doriti sa modificati?\n1.Numele\n2.Pretul\n3.Greutate\n4.Categoria\n5.Varsta\n0.Exit\n";
        cin >> j;

        switch (j)
        {
        case 1:
        {
            cout << "Introduceti noul nume al jucariei\n";
            cin.ignore();
            getline(cin, name);
            break;
        }
        case 2:
        {
            cout << "Introduceti noul pret al jucariei\n";
            cin >> price;
            break;
        }
        case 3:
        {
            cout << "Introduceti noua greutate a jucariei\n";
            cin >> weight;
            break;
        }
        case 4:
        {
            cout << "Introduceti noua categorie a jucariei\n";
            cin.ignore();
            getline(cin, category);
            break;
        }
        case 5:
        {
            cout << "Introduceti noua varsta jucariei\n";
            cin >> age;
            break;
        }
        default:
            break;
        }
    } while (j != 0);
}
void BToyClass::setId(int _id)
{

    id = _id;
}
