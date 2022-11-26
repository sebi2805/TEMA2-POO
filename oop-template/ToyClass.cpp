#include <iostream>
#include <string.h>
#include "ToyClass.h"
using namespace std;
ToyClass::ToyClass(const char *_name, float _price, float _weight, const char *_category, int _age, int _id)
{
    delete[] name;
    delete[] category;
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
    category = new char[strlen(_category) + 1];
    strcpy(category, _category);
    price = _price;
    weight = _weight;
    age = _age;
    id = _id;
}

ToyClass::ToyClass(const ToyClass &obj)
{
    delete[] name;
    delete[] category;
    name = new char[strlen(obj.name) + 1];
    category = new char[strlen(obj.category) + 1];
    strcpy(category, obj.category);
    strcpy(name, obj.name);
    price = obj.price;
    weight = obj.weight;
    age = obj.age;
    id = obj.id;
}

ToyClass &ToyClass::operator=(const ToyClass &obj)
{
    delete[] name;
    delete[] category;
    category = new char[strlen(obj.category) + 1];
    name = new char[strlen(obj.name) + 1];
    strcpy(name, obj.name);
    strcpy(category, obj.category);
    price = obj.price;
    weight = obj.weight;
    age = obj.age;

    id = obj.id;
    return *this;
};
bool operator==(const ToyClass &lhs, const ToyClass &rhs)
{
    bool res = (lhs.age == rhs.age) && lhs.price == rhs.price && lhs.weight == rhs.weight && (!strcmp(lhs.name, rhs.name)) && (!strcmp(lhs.category, rhs.category));
    return res;
};
bool operator!=(const ToyClass &lhs, const ToyClass &rhs)

{
    bool res = !(lhs.age == rhs.age) && lhs.price == rhs.price && lhs.weight == rhs.weight && (!strcmp(lhs.name, rhs.name)) && (!strcmp(lhs.category, rhs.category));
    return res; // !(*this == rhs)
};
ostream &operator<<(ostream &out, const ToyClass &obj)
{
    out << "    Id: " << obj.id << ". Numele jucariei este: " << obj.name << " cu pretul de " << obj.price << " si greutate de " << obj.weight << endl;
    return out;
};
istream &operator>>(istream &in, ToyClass &obj)
{
    cout << "Introduceti noul nume" << endl;
    cin.ignore();
    cin.getline(obj.name, 50);
    cout << "Introduceti pretul jucariei.\n";
    cin >> obj.price;
    cout << "Introduceti greutate.\n";
    cin >> obj.weight;
    cout << "Introduceti categoria\n";
    cin.ignore();
    cin.getline(obj.category, 50);
    cout << "Introduceti varsta recomandata.\n";
    cin >> obj.age;
    return in;
}
char *ToyClass::getName() const
{
    return name;
};
float ToyClass::getPrice()
{
    return price;
}
float ToyClass::getWeight()
{
    return weight;
}
int ToyClass::getAge()
{
    return age;
};

char *ToyClass::getCategory() const
{
    return category;
};
void ToyClass::setName(const char *_name)
{
    delete[] name;
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
};
void ToyClass::setCategory(const char *_category)
{
    delete[] category;
    category = new char[strlen(_category) + 1];
    strcpy(category, _category);
};
void ToyClass::setPrice(float _price)
{
    price = _price;
};
void ToyClass::setWeight(float _weight)
{
    weight = _weight;
};
void ToyClass::setAge(float _age) { age = _age; };
void ToyClass::updateToy()
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
            cin.getline(name, 50);
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
            cin.getline(category, 50);
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
void ToyClass::setId(int _id)
{

    id = _id;
}