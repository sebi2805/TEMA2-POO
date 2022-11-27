#include <iostream>
#include <string>
#include <vector>
#include "Gift.h"
#include "ClassicToy.h"
#include "ElectronicToy.h"
#include "EducativeToy.h"
#include "ModernToy.h"
#include <typeinfo>
int Gift::idClass = 1;

Gift::Gift(const string _name, const string _destination, const string _personName, vector<BToyClass *> _toys, int _toysLength)
{
    id = idClass;
    idClass++;
    name = _name;
    destination = _destination;
    personName = _personName;
    toysLength = _toysLength;
    // toys = _toys;
    // !!!!!!!!!!!!!!!!!
    idToys++;
}

Gift::Gift(const Gift &obj)
{

    toysLength = obj.toysLength;
    name = obj.name;
    destination = obj.destination;
    personName = obj.personName;
    toys = obj.toys;
}

Gift &Gift::operator=(const Gift &obj)
{

    toysLength = obj.toysLength;
    name = obj.name;
    destination = obj.destination;
    personName = obj.personName;
    toys = obj.toys;
    return *this;
}

istream &operator>>(istream &in, Gift &obj)
{

    cout << "Introduceti numele cadoului. (alegeti un nume sugestiv si fara spatii)\n";
    in.ignore();
    getline(in, obj.name);
    cout << "Introduceti destinatia cadoului.\n";
    getline(in, obj.destination);
    cout << "Introduceti destinatarului.\n";
    getline(in, obj.personName);
    cout << "Introduceti numarul de jucarii pe care vreti sa il adaugati initial. \n";
    in >> obj.toysLength;

    for (int j = 0; j < obj.toysLength; j++)
    {
        int type;
        cout << "**************Jucaria numarul: "
             << "**************\n**********************" << j + 1 << "**********************\nIntroduceti numele jucariei\n";
        cout << endl
             << "Ce tip de jucarie vreti sa introduceti?\n1.ClassicToy\n2.ElectronicToy\n3.EducativeToy\n4.ModernToy\n";
        in >> type;
        switch (type)
        {
        case 1:
        {

            obj.toys.push_back(make_unique<BToyClass>(dynamic_cast<BToyClass *>(new ClassicToy())));
            in >> *dynamic_cast<ClassicToy *>(obj.toys[j].get());
            break;
        }

        case 2:
        {

            obj.toys.push_back(dynamic_cast<BToyClass *>(new ElectronicToy()));
            in >> *dynamic_cast<ElectronicToy *>(obj.toys[j]);
            break;
        }
        case 3:
        {

            obj.toys.push_back(dynamic_cast<BToyClass *>(new EducativeToy()));
            in >> *dynamic_cast<EducativeToy *>(obj.toys[j]);
            break;
        }
        case 4:
        {

            obj.toys.push_back(dynamic_cast<BToyClass *>(new ModernToy()));
            in >> *dynamic_cast<ModernToy *>(obj.toys[j]);
            break;
        }

        default:
            break;
        }

        obj.toys[j]->setId(obj.idToys);
        obj.idToys++;
    }
    return in;
}
ostream &operator<<(ostream &out, Gift &obj)
{
    out << endl
        << " Id: " << obj.id << ". Numele cadoului este "
        << obj.name << " cu destinatia " << obj.destination << " pentru persoana " << obj.personName;
    out << endl;
    for (int i = 0; i < obj.toys.size(); i++)
    {

        if (dynamic_cast<ClassicToy *>(obj.toys[i]))
            cout << *dynamic_cast<ClassicToy *>(obj.toys[i]);
        else if (dynamic_cast<ElectronicToy *>(obj.toys[i]))
            cout << *dynamic_cast<ElectronicToy *>(obj.toys[i]);
        else if (dynamic_cast<EducativeToy *>(obj.toys[i]))
            cout << *dynamic_cast<EducativeToy *>(obj.toys[i]);
        else if (dynamic_cast<ModernToy *>(obj.toys[i]))
            cout << *dynamic_cast<ModernToy *>(obj.toys[i]);
    }
    out << endl;
    return out;
}
bool operator==(const Gift &lhs, const Gift &rhs)
{

    bool res = !lhs.destination.compare(rhs.destination) && !lhs.name.compare(rhs.name) && !lhs.personName.compare(rhs.personName);
    if (lhs.toys.size() != rhs.toys.size())
    {
        return false;
    }

    for (int i = 0; i < lhs.toys.size(); i++)
        if (*lhs.toys[i] != *rhs.toys[i]) // because we compare values, if we compare address its going to ve always false, i tried v1==v2
        {
            return false;
        }

    return res;
}

int Gift::getToysLength()
{
    return toysLength;
}
vector<BToyClass *> Gift::getToys()
{
    return toys;
}
const string Gift::getName() const
{
    return name;
}
const string Gift::getDestination() const
{
    return destination;
}
const string Gift::getPersonName() const
{
    return personName;
};
void Gift::setName(const string _name)
{
    name = _name;
};

void Gift::setDestination(const string _destination)
{
    destination = _destination;
};

void Gift::setPersonName(const string _personName)
{
    personName = _personName;
};
void Gift::setToys(const vector<BToyClass *> _toys, const int _toysLength)
{
    toys.clear();
    toys = _toys;
}
void Gift::updateGift()
{
    int j;
    do
    {
        cout << "Ce parametru doriti sa modificati?\n1.Nume cadou\n2.Destinatie cadou\n3.Destinatar cadou\n4.Adaugare jucarie noua\n5.Modificare jucarie existent\n6.Stergere jucarie existenta\n0.Exit\n";
        cin >> j;

        switch (j)
        {
        case 1:
        {
            cout << "Introduceti noul nume.\n";
            cin.ignore();
            getline(cin, name);
            break;
        }

        case 2:
        {

            cout << "Introduceti noua destinatie.\n";
            cin.ignore();
            getline(cin, destination);

            break;
        }
        case 3:
        {

            cout << "Introduceti noul destinatar.\n";
            cin.ignore();
            getline(cin, personName);

            break;
        }
        case 4:
        {
            toysLength++;
            BToyClass *auxToy;

            cout << "**************Jucaria numarul: "
                 << "**************\n**********************" << toysLength << "**********************\n";
            cin >> *auxToy;
            auxToy->setId(idToys);
            idToys++;
            toys.push_back(auxToy);

            break;
        }
        case 5:
        {
            int j;
            cout << "Ce jucarie vreti sa modificati?\n";
            cin >> j;
            toys[j - 1]->updateToy();
            break;
        }
        case 6:
        {
            int j;
            cout << "Ce jucarie vreti sa stergeti?\n";
            cin >> j;
            if (j > toysLength)
                cout << "Aceasta jucarie nu exista\n";
            else
            {
                toys.erase(toys.begin() + j);
                toysLength--;
                cout << "Stergere reusita\n";
            }

            break;
        }
        default:
            return;
            break;
        }
    } while (j != 0);
}
void Gift::summariseGift()
{
    int sumPrice = 0, sumWeight = 0;
    for (int i = 0; i < toysLength; i++)
    {
        sumPrice += toys[i]->getPrice();
        sumWeight += toys[i]->getWeight();
    }
    cout << "Pentru cadoul " << name << " pretul total este de " << sumPrice << " cu greutatea de " << sumWeight << endl;
}