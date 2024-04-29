#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    std::cout << "FragTrap:: Default constructor called for " << getName() << std::endl;
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);

    std::cout << "FragTrap:: Constructor called for " << getName() << std::endl;
}

FragTrap::FragTrap(const FragTrap &original) : ClapTrap(original)
{
    std::cout << "FragTrap:: Copy constructor called for " << getName() << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap:: Destructor called for " << getName() << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &original)
{
	if (this != &original)
	{
        ClapTrap::operator=(original);
	}
	std::cout << "FragTrap:: Assignment operator used for " << getName() << std::endl;
	return (*this);
}

//////////////////////////////////////////////////////////////////////////////////////

void FragTrap::attack(const std::string &target)
{
    if (getEnergyPoints() && getHitPoints())
    {
        setEnergyPoints(getEnergyPoints() - 1);
        //target.takeDamage(_attackDamage);
        std::cout   << "FragTrap " << getName() << " attacks " << target
                    << ", causing " << getAttackDamage() << " points of damage!"
                    << std::endl;
    }
    else if (!getEnergyPoints() && getHitPoints())
		std::cout << "FragTrap " << getName() << " hasn't energy to attack " << target << std::endl;
	else
		std::cout << "FragTrap " << getName() << " is dead and cannot attack " << target << std::endl;
}

// void FragTrap::guardGate()
// {
//     std::cout << "FragTrap " << getName() << " is in Gate keeper mode" << std::endl;
// }

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << getName() << " says: Who's up for a 🖐️ people?!" << std::endl;
}