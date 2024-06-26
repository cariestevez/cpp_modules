#include "Weapon.hpp"

//consructor. Takes a string as parameter, which is the weapon type
Weapon::Weapon(const char *initialType) : _type(initialType) {}

//returns a constant reference to type
const std::string   &Weapon::getType(void) const
{
    return (_type);
}

Weapon::~Weapon() {}

void   Weapon::setType(const std::string  &newType)
{
    _type = newType;
}
