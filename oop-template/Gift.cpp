#include <iostream>
#include <string>
#include <vector>
#include "Gift.h"
#include "ClassicToy.h"
#include "ElectronicToy.h"
#include "EducativeToy.h"
#include "ModernToy.h"
#include "MyExceptions.h"
#include <typeinfo>
int Gift::idClass = 1;
Gift::Gift(const std::string _name, const std::string _destination,
           const std::string _personName, std::vector<shared_ptr<BToyClass>> _toys, int _toysLength)
    : name(_name), destination(_destination), personName(_personName), toysLength(_toysLength), toys(_toys)
{
    id = idClass;
    idClass++;
    idToys++;
}
Gift::Gift(const Gift &obj) : toysLength(obj.toysLength), name(obj.name), destination(obj.destination),
                              personName(obj.personName), toys(obj.toys)
{
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

    std::cout << "Introduceti numele cadoului. (alegeti un nume sugestiv si fara spatii)\n";
    in.ignore();
    getline(in, obj.name);
    std::cout << "Introduceti destinatia cadoului.\n";
    getline(in, obj.destination);
    std::cout << "Introduceti destinatarului.\n";
    getline(in, obj.personName);
    std::cout << "Introduceti numarul de jucarii pe care vreti sa il adaugati initial. \n";
    in >> obj.toysLength;
    try
    {
        updateToyHelper(in, obj, false);
    }
    catch (ToyTypeExceptions ex)
    {
        std::cout << ex.what() << endl;
    }
    catch (ToyNotFound ex)
    {
        std::cout << ex.what() << endl;
    }
    catch (exception ex)
    {
        std::cout << ex.what() << endl;
    }
    catch (...)
    {
        std::cout << "A aparut o eroare in functia updateToyHolper";
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
        if (dynamic_cast<ClassicToy *>(obj.toys[i].get()))
        {
            out << "ClassicToy" << endl;
            out << *dynamic_cast<ClassicToy *>(obj.toys[i].get());
        }
        else if (dynamic_cast<ModernToy *>(obj.toys[i].get()))
        {
            out << "ModernToy" << endl;
            out << *dynamic_cast<ModernToy *>(obj.toys[i].get());
        }
        else if (dynamic_cast<ElectronicToy *>(obj.toys[i].get()))
        {
            out << "ElectronicToy" << endl;
            out << *dynamic_cast<ElectronicToy *>(obj.toys[i].get());
        }
        else if (dynamic_cast<EducativeToy *>(obj.toys[i].get()))
        {
            out << "EducativeToy" << endl;
            out << *dynamic_cast<EducativeToy *>(obj.toys[i].get());
        }
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
        if (*lhs.toys[i] != *rhs.toys[i])
        // because we compare values, if we compare address its going to ve always false, i tried v1==v2
        {
            return false;
        }

    return res;
}
const int Gift::getCurrentId()
{
    return idClass;
}
const int Gift::getToysLength() const
{
    return toysLength;
}
void Gift::setToysLength(int _toysLength)
{
    toysLength = _toysLength;
}
std::vector<shared_ptr<BToyClass>> Gift::getToys()
{
    return toys;
}
const std::string Gift::getName() const
{
    return name;
}
const std::string Gift::getDestination() const
{
    return destination;
}
const std::string Gift::getPersonName() const
{
    return personName;
};
const int Gift::getId() const
{
    return id;
};
void Gift::setName(const std::string _name)
{
    name = _name;
};
void Gift::setDestination(const std::string _destination)
{
    destination = _destination;
};
void Gift::setPersonName(const std::string _personName)
{
    personName = _personName;
};
void Gift::setToys(const std::vector<shared_ptr<BToyClass>> _toys, const int _toysLength)
{
    toys.clear();
    toys = _toys;
}
void Gift::updateGift()
{
    int j;
    do
    {
        std::cout << "Ce parametru doriti sa modificati?\n1.Nume cadou\n2.Destinatie cadou\n3.Destinatar cadou\n4.Adaugare jucarie noua\n5.Modificare jucarie existent\n6.Stergere jucarie existenta\n0.Exit\n";
        std::cin >> j;

        switch (j)
        {
        case 1:
        {
            std::cout << "Introduceti noul nume.\n";
            std::cin.ignore();
            getline(cin, name);
            break;
        }

        case 2:
        {

            std::cout << "Introduceti noua destinatie.\n";
            std::cin.ignore();
            getline(cin, destination);

            break;
        }
        case 3:
        {

            std::cout << "Introduceti noul destinatar.\n";
            std::cin.ignore();
            getline(cin, personName);

            break;
        }
        case 4:
        {
            toysLength++;
            updateToyHelper(cin, *this, true);
            break;
        }

        case 5:
        {
            int j;
            std::cout << "Ce jucarie vreti sa modificati?\n";
            std::cin >> j;
            toys[j - 1]->updateToy();
            break;
        }
        case 6:
        {
            int j;
            std::cout << "Ce jucarie vreti sa stergeti?\n";
            std::cin >> j;
            if (j > toysLength)
                std::cout << "Aceasta jucarie nu exista\n";
            else
            {
                toys.erase(toys.begin() + j);
                toysLength--;
                std::cout << "Stergere reusita\n";
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
    float sumPrice = 0, sumWeight = 0, classicToyCount = 0, electronicToyCount = 0, educativeToyCount = 0, modernToyCount = 0;
    for (int i = 0; i < toys.size(); i++)
    {

        if (dynamic_cast<ClassicToy *>(toys[i].get()))
            classicToyCount++;
        else if (dynamic_cast<ModernToy *>(toys[i].get()))
            modernToyCount++;
        else if (dynamic_cast<ElectronicToy *>(toys[i].get()))
            electronicToyCount++;
        else if (dynamic_cast<EducativeToy *>(toys[i].get()))
            educativeToyCount++;
        sumPrice += toys[i]->getPrice();
        sumWeight += toys[i]->getWeight();
    }
    std::cout << "Pentru cadoul " << name << " pretul total este de " << sumPrice << " cu greutatea de " << sumWeight
              << endl
              << "Numar jucarii clasice: " << classicToyCount << endl
              << "Numar jucarii electronice: " << electronicToyCount << endl
              << "Numar jucarii educative: " << educativeToyCount << endl
              << "Numar jucarii moderne: " << modernToyCount << endl;
}
void updateToyHelper(istream &in, Gift &obj, bool update)
{
    cout << "sebi update";
    update ? obj.toysLength++ : obj.toysLength;
    for (int j = update ? obj.toysLength - 2 : 0; j < (update ? obj.toysLength - 1 : obj.toysLength); j++)
    {
        cout << j << " " << obj.toysLength;
        int type;
        std::cout << "**************Jucaria numarul: "
                  << "**************\n**********************" << j + 1 << "**********************\nIntroduceti numele jucariei\n";
        std::cout << endl
                  << "Ce tip de jucarie vreti sa introduceti?\n1.ClassicToy\n2.ElectronicToy\n3.EducativeToy\n4.ModernToy\n";
        in >> type;
        switch (type)
        {
        case 1:
        {
            obj.toys.push_back(make_shared<ClassicToy>());
            in >> *dynamic_cast<ClassicToy *>(obj.toys[j].get());
            break;
        }

        case 2:
        {

            obj.toys.push_back(make_shared<ElectronicToy>());
            in >> *dynamic_cast<ElectronicToy *>(obj.toys[j].get());

            break;
        }
        case 3:
        {
            obj.toys.push_back(make_shared<EducativeToy>());
            in >> *dynamic_cast<EducativeToy *>(obj.toys[j].get());
            break;
        }
        case 4:
        {
            obj.toys.push_back(make_shared<ModernToy>());
            in >> *dynamic_cast<ModernToy *>(obj.toys[j].get());

            break;
        }

        default:
            throw ToyTypeExceptions();
            break;
        }
        obj.toys[j]->setId(obj.idToys);
        obj.idToys++;
    }
}