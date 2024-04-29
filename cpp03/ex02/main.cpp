#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap baseTrap = ClapTrap("Madre");
    std::cout   << baseTrap.getName() << " initial values (hitPoints - energyPoints - attackDamage): "
                << baseTrap.getHitPoints() << " - "
                << baseTrap.getEnergyPoints() << " - "
                << baseTrap.getAttackDamage()
                << std::endl;
    
    std::cout << std::endl;

    ScavTrap firstDerivedTrap = ScavTrap("Pepito");
    std::cout   << firstDerivedTrap.getName() << " initial values (hitPoints - energyPoints - attackDamage): "
                << firstDerivedTrap.getHitPoints() << " - "
                << firstDerivedTrap.getEnergyPoints() << " - "
                << firstDerivedTrap.getAttackDamage()
                << std::endl;

    std::cout << std::endl;

    FragTrap secondDerivedTrap = FragTrap("Anacletito");
    std::cout   << secondDerivedTrap.getName() << " initial values (hitPoints - energyPoints - attackDamage): "
                << secondDerivedTrap.getHitPoints() << " - "
                << secondDerivedTrap.getEnergyPoints() << " - "
                << secondDerivedTrap.getAttackDamage()
                << std::endl;
    
    std::cout << std::endl;

    FragTrap anotherDerivedTrap;
    std::cout   << anotherDerivedTrap.getName() << " initial values (hitPoints - energyPoints - attackDamage): "
                << anotherDerivedTrap.getHitPoints() << " - "
                << anotherDerivedTrap.getEnergyPoints() << " - "
                << anotherDerivedTrap.getAttackDamage()
                << std::endl;

    std::cout << std::endl;

    std::cout << "ACTION" << std::endl;
    std::cout << "......Pepito attacks his brother Anacletito:......" << std::endl;
    firstDerivedTrap.attack("Anacletito");//Pepito attacks his brother Anacletito
    std::cout << "......Anacletito loses hitPoints:......" << std::endl;
    secondDerivedTrap.takeDamage(firstDerivedTrap.getAttackDamage());//Anacletito loses _attackDamage of Pepito(= 0)
    std::cout << "......Anacletito heals him self:......" << std::endl;
    secondDerivedTrap.beRepaired(5);//Anacletito heals him self and has now +5 _hitPoints (=15)

    std::cout << std::endl;

    std::cout   << baseTrap.getName() << " values before initializing Randomeo (hitPoints - energyPoints - attackDamage): "
                << baseTrap.getHitPoints() << " - "
                << baseTrap.getEnergyPoints() << " - "
                << baseTrap.getAttackDamage()
                << std::endl;
    
    std::cout << std::endl;

    std::cout   << firstDerivedTrap.getName() << " values before initializing Randomeo (hitPoints - energyPoints - attackDamage): "
                << firstDerivedTrap.getHitPoints() << " - "
                << firstDerivedTrap.getEnergyPoints() << " - "
                << firstDerivedTrap.getAttackDamage()
                << std::endl;
    
    std::cout << std::endl;

    std::cout   << secondDerivedTrap.getName() << " values before initializing Randomeo (hitPoints - energyPoints - attackDamage): "
                << secondDerivedTrap.getHitPoints() << " - "
                << secondDerivedTrap.getEnergyPoints() << " - "
                << secondDerivedTrap.getAttackDamage()
                << std::endl;
    
    std::cout << std::endl;

    std::cout   << anotherDerivedTrap.getName() << " values before initializing Randomeo (hitPoints - energyPoints - attackDamage): "
                << anotherDerivedTrap.getHitPoints() << " - "
                << anotherDerivedTrap.getEnergyPoints() << " - "
                << anotherDerivedTrap.getAttackDamage()
                << std::endl;
    
    std::cout << std::endl;

    anotherDerivedTrap = FragTrap("Randomeo");
    std::cout   << anotherDerivedTrap.getName() << " initial values (hitPoints - energyPoints - attackDamage): "
                << anotherDerivedTrap.getHitPoints() << " - "
                << anotherDerivedTrap.getEnergyPoints() << " - "
                << anotherDerivedTrap.getAttackDamage()
                << std::endl;
    
    std::cout << std::endl;

    std::cout << "ACTION" << std::endl;
    std::cout << "......Pepito gains power:......" << std::endl;
    firstDerivedTrap.setAttackDamage(100);
    std::cout << "......Randomeo is cheering his half-siblings:......" << std::endl;
    anotherDerivedTrap.highFivesGuys();
    std::cout << "......Pepito attacks his brother Anacletito:......" << std::endl;
    firstDerivedTrap.attack("Anacletito");
    std::cout << "......Anacletito loses hitPoints......:" << std::endl;
    secondDerivedTrap.takeDamage(firstDerivedTrap.getAttackDamage());
    std::cout << "......Pepito attacks his brother Anacletito again:......" << std::endl;
    firstDerivedTrap.attack("Anacletito");
    std::cout << "......Anacletito should be dead:......" << std::endl;
    secondDerivedTrap.takeDamage(firstDerivedTrap.getAttackDamage());
    secondDerivedTrap.attack("Pepito");

    std::cout << std::endl;

    std::cout   << baseTrap.getName() << " current values (hitPoints - energyPoints - attackDamage): "
                << baseTrap.getHitPoints() << " - "
                << baseTrap.getEnergyPoints() << " - "
                << baseTrap.getAttackDamage()
                << std::endl;
    
    std::cout << std::endl;
    
    std::cout   << firstDerivedTrap.getName() << " current values (hitPoints - energyPoints - attackDamage): "
                << firstDerivedTrap.getHitPoints() << " - "
                << firstDerivedTrap.getEnergyPoints() << " - "
                << firstDerivedTrap.getAttackDamage()
                << std::endl;

    std::cout << std::endl;

    std::cout   << secondDerivedTrap.getName() << " current values (hitPoints - energyPoints - attackDamage): "
                << secondDerivedTrap.getHitPoints() << " - "
                << secondDerivedTrap.getEnergyPoints() << " - "
                << secondDerivedTrap.getAttackDamage()
                << std::endl;
    
    std::cout << std::endl;

    std::cout   << anotherDerivedTrap.getName() << " current values (hitPoints - energyPoints - attackDamage): "
                << anotherDerivedTrap.getHitPoints() << " - "
                << anotherDerivedTrap.getEnergyPoints() << " - "
                << anotherDerivedTrap.getAttackDamage()
                << std::endl;
    
    std::cout << std::endl;
}