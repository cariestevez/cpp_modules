#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

void HumanB::setWeapon(const Weapon &weaponObject)//we need the address of the object, to not create a copy
{
    _weapon = &weaponObject;//give _weapon the address of the initialized object, so both point to the same 
}

HumanB::~HumanB() {}

void HumanB::attack(void)
{
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " has no weapon!" << std::endl;
}