#include "Zombie.hpp"
#include <iostream>

//constructor
Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "Zombie " << _name << " created" << std::endl;
}

//destructor
Zombie::~Zombie(void)
{
    std::cout << "Zombie " << _name << " destructed" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
