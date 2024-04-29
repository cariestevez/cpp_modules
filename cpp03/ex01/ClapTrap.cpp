#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("no name"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap:: Default constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap:: Constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original)
{
    _name = original._name;
    _hitPoints = original._hitPoints;
    _energyPoints = original._hitPoints;
    _attackDamage = original._attackDamage;
    std::cout << "ClapTrap:: Copy constructor called for " << _name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap:: Destructor called for " << _name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &original)
{
	if (this != &original)
	{
		_name = original._name;
		_hitPoints = original._hitPoints;
		_energyPoints = original._energyPoints;
		_attackDamage = original._attackDamage;
	}
	std::cout << "ClapTrap:: Assignment operator used for " << _name << std::endl;
	return (*this);
}

//////////////////////////////////////////////////////////////////////////////////////

std::string     ClapTrap::getName(void) { return _name; }
unsigned int	ClapTrap::getHitPoints(void) const { return _hitPoints; }
unsigned int	ClapTrap::getEnergyPoints(void) const { return _energyPoints; }
unsigned int    ClapTrap::getAttackDamage(void) const { return _attackDamage; }

void    ClapTrap::setHitPoints(unsigned int amount) { _hitPoints = amount; }
void    ClapTrap::setEnergyPoints(unsigned int amount) { _energyPoints = amount; }
void    ClapTrap::setAttackDamage(unsigned int amount) { _attackDamage = amount; }

//////////////////////////////////////////////////////////////////////////////////////

void ClapTrap::attack(const std::string &target)
{
    if (_energyPoints && _hitPoints)
    {
        _energyPoints -= 1;
        //target.takeDamage(_attackDamage);
        std::cout   << "ClapTrap " << _name << " attacks " << target
                    << ", causing " << _attackDamage << " points of damage!"
                    << std::endl;
    }
    else if (!_energyPoints && _hitPoints)
		std::cout << "ClapTrap " << _name << " hasn't energy to attack " << target << std::endl;
	else
		std::cout << "ClapTrap " << _name << " is dead and cannot attack " << target << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints >= amount)
	{
		_hitPoints -= amount;
        std::cout   << "ClapTrap " << getName() << " loses " << amount
                    << " hit points!"
                    << std::endl;
	}
	else
	{
        std::cout   << "ClapTrap " << getName() << " loses " << _hitPoints 
                    << " hit points!"
                    << std::endl;
		_hitPoints = 0;
	}
	if (!_hitPoints)
		std::cout << "ClapTrap " << _name << " is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints && _hitPoints)
    {
        _hitPoints += amount;
        _energyPoints -= 1;
        std::cout   << "ClapTrap " << getName() << " recovers " << amount
                    << " hit points!"
                    << std::endl;
    }
}