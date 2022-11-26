#ifndef CLASSIC_TOY
#define CLASSIC_TOY
#include "BToyClass.h"
class ClassicToy : public BToyClass
{
    string material, color;

public:
    ClassicToy(const string _name = "undefined", float _price = 0, float _weight = 0,
               const string _category = "none", int _age = 3, int _id = 1,
               string material = "plastic", string color = "negru");
    ClassicToy(const ClassicToy &obj);
    const string getMaterial() const;
    const string getColor() const;
    void setMaterial(const string _material);
    void setColor(const string _culoare);
    bool operator==(const ClassicToy &obj);
    bool operator!=(const ClassicToy &obj);
    friend ostream &operator<<(ostream &out, const ClassicToy &obj);
    friend istream &operator>>(istream &in, ClassicToy &obj);
    ClassicToy &operator=(const ClassicToy &obj);
};
#endif