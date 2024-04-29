#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
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