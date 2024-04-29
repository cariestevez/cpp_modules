#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    std::cout << "\e[0;34mFragTrap::\033[0m Default constructor called for " << _name << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "\e[0;34mFragTrap::\033[0m Constructor called for " << _name << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &original) : ClapTrap(original)
{
    std::cout << "\e[0;34mFragTrap::\033[0m Copy constructor called for " << _name << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "\e[0;34mFragTrap::\033[0m Destructor called for " << _name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &original)
{
	if (this != &original)
        ClapTrap::operator=(original);
	std::cout << "\e[0;34mFragTrap::\033[0m Assignment operator used for " << _name << std::endl;
	return (*this);
}

//////////////////////////////////////////////////////////////////////////////////////

void FragTrap::attack(const std::string &target)
{
    if (_energyPoints && _hitPoints)
    {
        _energyPoints--;
        std::cout   << "\e[1;34mFragTrap " << _name << " attacks " << target
                    << ", causing " << _attackDamage << " points of damage!\033[0m"
                    << std::endl;
    }
    else if (!_energyPoints && _hitPoints)
		std::cout << "\e[1;34mFragTrap " << _name << " hasn't energy to attack " << target << "\033[0m" << std::endl;
	else
		std::cout << "\e[1;34mFragTrap " << _name << " is dead and cannot attack " << target << "\033[0m" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "\e[1;34mFragTrap " << _name << " says: Who's up for a 🖐️ people?!\033[0m" << std::endl;
}