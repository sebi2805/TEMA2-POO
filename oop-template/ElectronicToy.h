#ifndef ELECTRONIC_TOY
#define ELECTRONIC_TOY
#include "BToyClass.h"
#include "BPlay.h"
class ElectronicToy : virtual public BToyClass, BPlay
{
    int numberBaterries;

public:
    ElectronicToy(const string _name = "undefined", float _price = 0, float _weight = 0,
                  const string _category = "none", int _age = 3, int _id = 1,
                  int numberBaterries = 1);
    ElectronicToy(const ElectronicToy &obj);
    const int getNumberBatteries() const;
    void setNumberBatteries(const int _numberBatteries);
    bool operator==(const ElectronicToy &obj);
    bool operator!=(const ElectronicToy &obj);
    void playSound() override;
    ElectronicToy &operator=(const ElectronicToy &obj);
    friend ostream &operator<<(ostream &out, ElectronicToy &obj);
    friend istream &operator>>(istream &in, ElectronicToy &obj);
    virtual ~ElectronicToy() {}
};
#endif
