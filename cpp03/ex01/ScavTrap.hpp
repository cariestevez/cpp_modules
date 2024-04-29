#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
    /* data */
public:
    ScavTrap(/* args */);
    ScavTrap(std::string name);
   // ScavTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage) ;
    ScavTrap(const ScavTrap &original);
    ~ScavTrap();

    ScavTrap    &operator=(const ScavTrap &original);


    void guardGate();
    void attack(const std::string &target);
};

#endif