#include "MyExceptions.h"
const char *ToyTypeExceptions::what() const noexcept
{
    return "This type of toy doesn't exist";
}
const char *GiftNotFound::what() const noexcept
{
    return "This gift number doesn't exist";
}
const char *ToyNotFound::what() const noexcept
{
    return "This toy number doesn't exist";
}