#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

//using virtual keyword to avoid creating a instance of ClapTrap for each of the derived classes the new class inherits from
class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &original);
    FragTrap &operator=(const FragTrap &original);
    ~FragTrap();

    // void guardGate();
    void highFivesGuys(void);
    void attack(const std::string &target);
};

#endif