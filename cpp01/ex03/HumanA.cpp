#include "HumanA.hpp"

//func takes a name and a weapon class object as parameters
//member variables of a class are initialized before the body of the constructor is executed!!
//so weapon has to be initialized in the function declaration
//doing it inside of the function body is assignment, not init!
HumanA::HumanA(std::string name, const Weapon &weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack(void)
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}