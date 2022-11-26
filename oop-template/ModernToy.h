#ifndef MODERN_TOY
#define MODERN_TOY
#include "ElectronicToy.h"
#include "EducativeToy.h"
class ModernToy : public ElectronicToy, EducativeToy
{
    string brand;

public:
    ModernToy(const string _name = "undefined", float _price = 0, float _weight = 0,
              const string _category = "none", int _age = 3, int _id = 1,
              string brand = "general", int numberBatteries = 1, string abilityLearned = "general");
    ModernToy(const ModernToy &obj);
    const string getAbilityLearned() const;
    void setAbilityLearned(const string _abilityLearned);
    bool operator==(const ModernToy &obj);
    bool operator!=(const ModernToy &obj);
    friend ostream &operator<<(ostream &out, ModernToy &obj);
    friend istream &operator>>(istream &in, ModernToy &obj);
    ModernToy &operator=(const ModernToy &obj);
    virtual ~ModernToy() {}
};
#endif
