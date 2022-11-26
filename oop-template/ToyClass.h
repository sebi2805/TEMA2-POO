#ifndef TOYCLASS_J
#define TOYCLASS_J
#include <iostream>
#include <ostream>
#include <string.h>
using namespace std;
class ToyClass
{
private:
    char *name = new char[1], *category = new char[1];
    float price, weight;
    int age;
    int id;

public:
    ToyClass(const char *_name = "undefined", float _price = 0, float _weight = 0, const char *_category = "none", int _age = 3, int _id = 1);
    ToyClass(const ToyClass &obj);
    ToyClass &operator=(const ToyClass &obj);
    friend ostream &operator<<(ostream &out, const ToyClass &obj);
    friend istream &operator>>(istream &in, ToyClass &obj);
    friend bool operator==(const ToyClass &lhs, const ToyClass &rhs);
    friend bool operator!=(const ToyClass &lhs, const ToyClass &rhs);
    float getPrice();
    float getWeight();
    int getAge();
    char *getName() const;
    char *getCategory() const;
    void setName(const char *_name);
    void setCategory(const char *category);
    void setPrice(float _price);
    void setWeight(float _weight);
    void setAge(float _age);
    void updateToy();
    void setId(int id);
    ~ToyClass()
    {
        delete[] name;
        delete[] category;
    }
};
#endif