#include "Zombie.hpp"
#include <iostream>

//constructor
Zombie::Zombie(void)
{
    std::cout << "Zombie created" << std::endl;
}

//parameterized constructor
//Zombie::Zombie(std::string name) : _name(name){} // cannot be used when creating an array of instances of a class

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
We can't do it in this case bc the allocation of the array doesn't accept arguments (we would need the name arg to init the zombie)
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
