#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

//FragTrap overrides the values of ScavTrap for DiamondTrap
class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string _name;
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &original);
    DiamondTrap &operator=(const DiamondTrap &original);
    ~DiamondTrap();

    void whoAmI();
    using	ScavTrap::attack;
};

#endif