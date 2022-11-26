#include <iostream>
#include <string.h>
#include "Gift.h"
int Gift::idClass = 1;

Gift::Gift(const char *_name, const char *_destination, const char *_personName, ToyClass *_toys, int _toysLength)
{
    id = idClass;
    idClass++;
    name = new char[strlen(_name)];
    destination = new char[strlen(_destination)];
    personName = new char[strlen(_personName)];
    toysLength = _toysLength;
    toys = new ToyClass[toysLength];
    strcpy(name, _name);
    strcpy(personName, _personName);
    strcpy(destination, _destination);
    for (int i = 0; i < toysLength; i++)
    {
        toys[i] = _toys[i];
        toys[i].setId(idToys);
        idToys++;
    }
}

Gift::Gift(const Gift &obj)
{
    delete[] name;
    delete[] destination;
    delete[] toys;
    delete[] personName;
    toysLength = obj.toysLength;
    name = new char[strlen(obj.name)];
    destination = new char[strlen(obj.destination)];
    personName = new char[strlen(obj.personName)];
    toys = new ToyClass[obj.toysLength];
    strcpy(name, obj.name);
    strcpy(destination, obj.name);
    strcpy(personName, obj.personName);
    for (int i = 0; i < toysLength; i++)
        toys[i] = obj.toys[i];
}

Gift &Gift::operator=(const Gift &obj)
{
    delete[] name;
    delete[] destination;
    delete[] toys;
    delete[] personName;
    toysLength = obj.toysLength;
    name = new char[strlen(obj.name)];
    destination = new char[strlen(obj.destination)];
    personName = new char[strlen(obj.personName)];
    toys = new ToyClass[obj.toysLength];
    strcpy(name, obj.name);
    strcpy(destination, obj.name);
    strcpy(personName, obj.personName);
    for (int i = 0; i < toysLength; i++)
        toys[i] = obj.toys[i];
    return *this;
}
istream &operator>>(istream &in, Gift &obj)
{
    delete[] obj.name;
    delete[] obj.destination;
    delete[] obj.personName;
    delete[] obj.toys;
    obj.name = new char[50];
    obj.destination = new char[50];
    obj.personName = new char[50];
    cout << "Introduceti numele cadoului. (alegeti un nume sugestiv si fara spatii)\n";
    in.ignore();
    in.getline(obj.name, 50);
    cout << "Introduceti destinatia cadoului.\n";
    in.getline(obj.destination, 50);
    cout << "Introduceti destinatarului.\n";
    in.getline(obj.personName, 50);
    cout << "Introduceti numarul de jucarii pe care vreti sa il adaugati initial. \n";
    in >> obj.toysLength;

    obj.toys = new ToyClass[obj.toysLength];
    for (int j = 0; j < obj.getToysLength(); j++)
    {
        cout << "**************Jucaria numarul: "
             << "**************\n**********************" << j + 1 << "**********************\nIntroduceti numele jucariei\n";
        in >> obj.toys[j];
        obj.toys[j].setId(obj.idToys);
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
        cout << obj.toys[i];
    out << endl;
    return out;
}
bool operator==(const Gift &lhs, const Gift &rhs)
{

    bool res = !strcmp(lhs.destination, rhs.destination) && !strcmp(lhs.name, rhs.name) && !strcmp(lhs.personName, rhs.personName);
    if (lhs.toysLength != rhs.toysLength)
        return false;
    for (int i = 0; i < lhs.toysLength; i++)
    {
        cout << i;
        if (lhs.toys[i] == rhs.toys[i])
            return false;
    }
    return res;
}

int Gift::getToysLength()
{
    return toysLength;
}
ToyClass *Gift::getToys() const
{
    return toys;
}
char *Gift::getName() const
{
    return name;
}
char *Gift::getDestination() const
{
    return destination;
}
char *Gift::getPersonName() const
{
    return personName;
};
void Gift::setName(const char *_name)
{
    delete[] name;
    size_t lenght_name = strlen(_name);
    name = new char[lenght_name];
    strcpy(name, _name);
};
void Gift::setDestination(const char *_destination)
{
    delete[] destination;
    size_t lenght_name = strlen(_destination);
    name = new char[lenght_name];
    strcpy(name, _destination);
};
void Gift::setPersonName(const char *_personName)
{
    delete[] personName;
    size_t lenght_name = strlen(_personName);
    name = new char[lenght_name];
    strcpy(name, _personName);
};
void Gift::setToys(const ToyClass *_toys, const int _toysLength)
{
    delete[] toys;
    toysLength = _toysLength;
    toys = new ToyClass[toysLength];
    for (int i = 0; i < toysLength; i++)
    {
        toys[i] = _toys[i];
    }
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
            cin.getline(name, 50);
            break;
        }

        case 2:
        {

            cout << "Introduceti noua destinatie.\n";
            cin.ignore();
            cin.getline(destination, 50);

            break;
        }
        case 3:
        {

            cout << "Introduceti noul destinatar.\n";
            cin.ignore();
            cin.getline(personName, 50);

            break;
        }
        case 4:
        {
            toysLength++;

            ToyClass *auxToys = new ToyClass[toysLength];
            for (int k = 0; k < toysLength - 1; k++)
            {
                auxToys[k] = toys[k];
            }
            cout << "**************Jucaria numarul: "
                 << "**************\n**********************" << toysLength << "**********************\n";
            cin >> auxToys[toysLength - 1];
            auxToys[toysLength - 1].setId(idToys);
            idToys++;
            delete[] toys;
            toys = new ToyClass[toysLength];
            for (int k = 0; k < toysLength; k++)
            {
                toys[k] = auxToys[k];
            }
            break;
        }
        case 5:
        {
            int j;
            cout << "Ce jucarie vreti sa modificati?\n";
            cin >> j;
            toys[j - 1].updateToy();
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
                for (int i = j - 1; i < toysLength - 1; i++)
                    toys[i] = toys[i + 1];
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
        sumPrice += toys[i].getPrice();
        sumWeight += toys[i].getWeight();
    }
    cout << "Pentru cadoul " << name << " pretul total este de " << sumPrice << " cu greutatea de " << sumWeight << endl;
}