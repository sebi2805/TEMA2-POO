#ifndef BToyClass_J
#define BToyClass_J
#include <iostream>
#include <ostream>
#include <string.h>
using namespace std;

class BToyClass
{
private:
    string name, category;
    float price, weight;
    int age;
    int id;
    bool isRead = false, isPrinted = false;

public:
    BToyClass(const string _name = "undefined", float _price = 0, float _weight = 0, const string _category = "none", int _age = 3, int _id = 1);
    BToyClass(const BToyClass &obj);
    BToyClass &operator=(const BToyClass &obj);
    virtual friend ostream &operator<<(ostream &out, BToyClass &obj);
    virtual friend istream &operator>>(istream &in, BToyClass &obj);
    bool operator==(const BToyClass &obj);
    bool operator!=(const BToyClass &obj);
    float getPrice();
    float getWeight();
    int getAge();
    virtual void afisare(ostream &out);
    const string getName() const;
    const string getCategory() const;
    void setName(const string _name);
    void setCategory(const string category);
    void setPrice(float _price);
    void setWeight(float _weight);
    void setAge(float _age);
    void setIsPrinted(bool isPrinted);
    void updateToy();
    void setId(int id);
    virtual ~BToyClass()
    {
    }
};
#endif