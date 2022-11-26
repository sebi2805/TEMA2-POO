#include <iostream>
#include <string>
#include <vector>
#include "Gift.h"
#include "ClassicToy.h"
#include "ElectronicToy.h"
#include "EducativeToy.h"
#include "ModernToy.h"
int Gift::idClass = 1;

Gift::Gift(const string _name, const string _destination, const string _personName, vector<BToyClass *> _toys, int _toysLength)
{
    id = idClass;
    idClass++;
    name = _name;
    destination = _destination;
    personName = _personName;
    toysLength = _toysLength;
    toys = _toys;

    // idToys++;
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

    obj.name = new char[50];
    obj.destination = new char[50];
    obj.personName = new char[50];
    cout << "Introduceti numele cadoului. (alegeti un nume sugestiv si fara spatii)\n";
    in.ignore();
    getline(in, obj.name);
    cout << "Introduceti destinatia cadoului.\n";
    getline(in, obj.destination);
    cout << "Introduceti destinatarului.\n";
    getline(in, obj.personName);
    cout << "Introduceti numarul de jucarii pe care vreti sa il adaugati initial. \n";
    in >> obj.toysLength;

    for (int j = 0; j < obj.getToysLength(); j++)
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
            ClassicToy aux;
            in >> aux;
            obj.toys.push_back(&aux);
            break;
        }
        case 2:
        {
            ElectronicToy aux;
            in >> aux;
            obj.toys.push_back(&aux);
            break;
        }
        case 3:
        {
            EducativeToy aux;
            in >> aux;
            obj.toys.push_back(&aux);
            break;
        }
        case 4:
        {
            ModernToy aux;
            in >> aux;
            obj.toys.push_back(&aux);
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
    for (int i = 0; i < obj.toysLength; i++)
        out << *(obj.toys[i]);
    out << endl;
    return out;
}
bool operator==(const Gift &lhs, const Gift &rhs)
{

    bool res = !lhs.destination.compare(rhs.destination) && !lhs.name.compare(rhs.name) && !lhs.personName.compare(rhs.personName);
    res = res && (lhs.toys == rhs.toys); //!!!!!!!!!!!!!!!!!!!!!!!!!
    return res;
}

int Gift::getToysLength()
{
    return toysLength;
}
const vector<BToyClass *> Gift::getToys() const
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