#include <iostream>
#include <string>
class ToyTypeExceptions : public std::exception
{
public:
    virtual const char *what() const noexcept override;
};
class GiftNotFound : public std::exception
{
public:
    virtual const char *what() const noexcept;
};
class ToyNotFound : public std::exception
{
public:
    virtual const char *what() const noexcept;
};