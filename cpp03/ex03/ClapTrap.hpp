#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

//setting private members to protected allows access to/from the derived classes
class ClapTrap
{
protected:
    std::string          _name;
    unsigned int         _hitPoints;
    unsigned int         _energyPoints;
    unsigned int         _attackDamage;
public:
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &original);
    ClapTrap &operator=(const ClapTrap &original);
    ~ClapTrap(void);
    
    std::string     getName(void);
    unsigned int	getHitPoints(void) const;
    unsigned int	getEnergyPoints(void) const;
    unsigned int    getAttackDamage(void) const;
    
    void setHitPoints(unsigned int amount);
    void setEnergyPoints(unsigned int amount);
    void setAttackDamage(unsigned int amount);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif