#include "Weapon.hpp"
 
Weapon::Weapon(std::string weapon)
{
}

Weapon::~Weapon()
{
}

 
std::string   Weapon::getType(void) const
{
    return (_type);
}

void   Weapon::setType(std::string  newType)
{
    _type = newType;
}

        