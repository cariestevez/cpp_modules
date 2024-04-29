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
    std::cout << "ScavTrap:: Default constructor called for " << getName() << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);

    std::cout << "ScavTrap:: Constructor called for " << getName() << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original)
{
    std::cout << "ScavTrap:: Copy constructor called for " << getName() << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap:: Destructor called for " << getName() << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &original)
{
	if (this != &original)
	{
        ClapTrap::operator=(original);
        //static_cast<ClapTrap&>(*this) = original;
	}
	std::cout << "ScavTrap:: Assignment operator used for " << getName() << std::endl;
	return (*this);
}

//////////////////////////////////////////////////////////////////////////////////////

void ScavTrap::attack(const std::string &target)
{
    if (getEnergyPoints() && getHitPoints())
    {
        setEnergyPoints(getEnergyPoints() - 1);
        //target.takeDamage(_attackDamage);
        std::cout   << "ScavTrap " << getName() << " attacks " << target
                    << ", causing " << getAttackDamage() << " points of damage!"
                    << std::endl;
    }
    else if (!getEnergyPoints() && getHitPoints())
		std::cout << "ScavTrap " << getName() << " hasn't energy to attack " << target << std::endl;
	else
		std::cout << "ScavTrap " << getName() << " is dead and cannot attack " << target << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << getName() << " is in Gate keeper mode" << std::endl;
}