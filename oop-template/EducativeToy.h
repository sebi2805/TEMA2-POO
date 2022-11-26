#ifndef EDUCATIVE_TOY
#define EDUCATIVE_TOY
#include "BToyClass.h"
class EducativeToy : virtual public BToyClass
{
    string abilityLearned;

public:
    EducativeToy(const string _name = "undefined", float _price = 0, float _weight = 0,
                 const string _category = "none", int _age = 3, int _id = 1,
                 string abilityLearned = "general");
    EducativeToy(const EducativeToy &obj);
    const string getAbilityLearned() const;
    void setAbilityLearned(const string _abilityLearned);
    bool operator==(const EducativeToy &obj);
    bool operator!=(const EducativeToy &obj);
    friend ostream &operator<<(ostream &out, const EducativeToy &obj);
    friend istream &operator>>(istream &in, EducativeToy &obj);
    EducativeToy &operator=(const EducativeToy &obj);
};
#endif
