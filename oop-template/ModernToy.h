#ifndef MODERN_TOY
#define MODERN_TOY
#include "ElectronicToy.h"
#include "EducativeToy.h"
#include "BPlay.h"
class ModernToy : public ElectronicToy, EducativeToy
{
    std::string brand;

public:
    ModernToy(const std::string _name = "undefined", float _price = 0, float _weight = 0,
              const std::string _category = "none", int _age = 3, int _id = 1,
              std::string brand = "general", int numberBatteries = 1, std::string abilityLearned = "general");
    ModernToy(const ModernToy &obj);
    const std::string getBrand() const;
    void setBrand(const std::string _abilityLearned);
    bool operator==(const ModernToy &obj);
    bool operator!=(const ModernToy &obj);
    void playSound() override;
    friend ostream &operator<<(ostream &out, ModernToy &obj);
    friend istream &operator>>(istream &in, ModernToy &obj);
    ModernToy &operator=(const ModernToy &obj);
    virtual ~ModernToy() {}
};
#endif
