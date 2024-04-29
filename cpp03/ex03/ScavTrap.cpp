#include "ScavTrap.hpp"

//will inherit the constructors and destructor from ClapTrap.
//its constructors, destructor and attack() will print different messages
//When a ScavTrap is created, the program starts by building a ClapTrap. Destruction is in reverse order
//ScavTrap will use the attributes of ClapTrap (update ClapTrap in consequence) and
//must initialize them to:
//• Name, which is passed as parameter to a constructor
// • Hit points (100), represent the health of the ClapTrap
// • Energy points (50)
// • Attack damage (20)
ScavTrap::ScavTrap(void) : ClapTrap()
{
    std::cout << "\e[0;33mScavTrap::\033[0m Default constructor called for " << _name << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "\e[0;33mScavTrap::\033[0m Constructor called for " << _name << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original)
{
    std::cout << "\e[0;33mScavTrap::\033[0m Copy constructor called for " << _name << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "\e[0;33mScavTrap::\033[0m Destructor called for " << _name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &original)
{
	if (this != &original)
        ClapTrap::operator=(original);
	std::cout << "\e[0;33mScavTrap::\033[0m Assignment operator used for " << _name << std::endl;
	return (*this);
}

//////////////////////////////////////////////////////////////////////////////////////

void ScavTrap::attack(const std::string &target)
{
    if (_energyPoints && _hitPoints)
    {
        _energyPoints--;
        std::cout   << "\e[1;33mScavTrap " << _name << " attacks " << target
                    << ", causing " << _attackDamage << " points of damage!\033[0m"
                    << std::endl;
    }
    else if (!_energyPoints && _hitPoints)
		std::cout << "\e[1;33mScavTrap " << _name << " hasn't energy to attack " << target << "\033[0m" << std::endl;
	else
		std::cout << "\e[1;33mScavTrap " << _name << " is dead and cannot attack " << target << "\033[0m" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "\e[1;33mScavTrap " << _name << " is in Gate keeper mode\033[0m" << std::endl;
}