#include "DiamondTrap.hpp"

// inherits from both the FragTrap
// AND the ScavTrap
// will have a name private attribute. Give to this attribute
// exactly the same variable’s name than the one in the ClapTrap base class.
// Its attributes and member functions will be picked from either one of its parent classes:
// • Name, which is passed as parameter to a constructor
// • ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
// • Hit points (FragTrap)
// • Energy points (ScavTrap)
// • Attack damage (FragTrap)
// • attack() (Scavtrap)
// the ClapTrap subobject of the DiamondTrap will be created once, and only once
DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _name("no_name")
{
    std::cout << "\033[31mDiamondTrap::\033[0m Default constructor called for " << _name << std::endl;
    ClapTrap::_name = _name + "_clap_name";
    _energyPoints = 50;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    std::cout << "\033[31mDiamondTrap::\033[0m Constructor called for " << _name << std::endl;
    _energyPoints = 50;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original) : ScavTrap(original), FragTrap(original)
{
    std::cout << "\033[31mDiamondTrap::\033[0m Copy constructor called for " << _name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &original)
{
    if (this != &original)
    {
        ClapTrap::_name = original.ClapTrap::_name;
        _name = original._name;
        _hitPoints = original._hitPoints;
		_energyPoints = original._energyPoints;
		_attackDamage = original._attackDamage;
    }
	std::cout << "\033[31mDiamondTrap::\033[0m Assignment operator used for " << _name << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "\033[31mDiamondTrap::\033[0m Destructor called for " << _name << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

void DiamondTrap::whoAmI()
{
    std::cout   << "\e[1;31mI am " << _name
                << " and I am " << ScavTrap::getName()
                << " at the same time\033[0m"
                << std::endl;
}