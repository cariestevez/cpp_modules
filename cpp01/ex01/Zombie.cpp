#include "Zombie.hpp"
#include <iostream>

//constructors
Zombie::Zombie(void)
{
    std::cout << "Zombie " << "created" << std::endl;
}

//Zombie::Zombie(std::string name) : _name(name){}

void    Zombie::rename(std::string name) 
{
    _name = name;
}
/*
Same as above but _name is assigned the value of name in the constructor body
This involves two steps:
1.default construction of _name
2.assignment
->less efficient than initialization in the member initializer list.
In Zombie::Zombie(std::string name) : _name(name) {}
_name is initialized directly in the member initializer list
->this is preferred because it initializes the member variable once during construction and is more efficient.
*/

//destructor
Zombie::~Zombie(void)
{
    std::cout << "Zombie " << _name << " destructed" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
