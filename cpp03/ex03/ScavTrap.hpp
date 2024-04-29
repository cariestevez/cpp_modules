#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

//using virtual keyword to avoid creating a instance of ClapTrap for each of the derived classes the new class inherits from
class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &original);
    ScavTrap &operator=(const ScavTrap &original);
    ~ScavTrap();

    void guardGate();
    void attack(const std::string &target);
};

#endif