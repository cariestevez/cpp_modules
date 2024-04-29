#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    ClapTrap baseTrap = ClapTrap("Madre");
    std::cout   << baseTrap.getName()
                << "\033[35m initial values (hitPoints - energyPoints - attackDamage): \033[0m"
                << baseTrap.getHitPoints() << " - "
                << baseTrap.getEnergyPoints() << " - "
                << baseTrap.getAttackDamage()
                << std::endl;
    
    std::cout << std::endl;

    ScavTrap firstDerivedTrap = ScavTrap("Pepito");
    std::cout   << firstDerivedTrap.getName()
                << "\033[35m initial values (hitPoints - energyPoints - attackDamage): \033[0m"
                << firstDerivedTrap.getHitPoints() << " - "
                << firstDerivedTrap.getEnergyPoints() << " - "
                << firstDerivedTrap.getAttackDamage()
                << std::endl;

    std::cout << std::endl;

    FragTrap secondDerivedTrap = FragTrap("Anacletito");
    std::cout   << secondDerivedTrap.getName()
                << "\033[35m initial values (hitPoints - energyPoints - attackDamage): \033[0m"
                << secondDerivedTrap.getHitPoints() << " - "
                << secondDerivedTrap.getEnergyPoints() << " - "
                << secondDerivedTrap.getAttackDamage()
                << std::endl;
    
    std::cout << std::endl;

    DiamondTrap diamondTrap1;
    std::cout   << diamondTrap1.getName()
                << "\033[35m initial values (hitPoints - energyPoints - attackDamage): \033[0m"
                << diamondTrap1.getHitPoints() << " - "
                << diamondTrap1.getEnergyPoints() << " - "
                << diamondTrap1.getAttackDamage()
                << std::endl;
    diamondTrap1.whoAmI();
    
    std::cout << std::endl;
    
    DiamondTrap diamondTrap2 = DiamondTrap("evilDiamond");
    std::cout   << diamondTrap2.getName()
                << "\033[35m initial values (hitPoints - energyPoints - attackDamage): \033[0m"
                << diamondTrap2.getHitPoints() << " - "
                << diamondTrap2.getEnergyPoints() << " - "
                << diamondTrap2.getAttackDamage()
                << std::endl;
    
    std::cout << std::endl;

    diamondTrap1 = diamondTrap2;
    std::cout   << diamondTrap1.getName()
                << "\033[35m initial values (hitPoints - energyPoints - attackDamage): \033[0m"
                << diamondTrap1.getHitPoints() << " - "
                << diamondTrap1.getEnergyPoints() << " - "
                << diamondTrap1.getAttackDamage()
                << std::endl;
    diamondTrap1.whoAmI();
    
    std::cout << std::endl;

    std::cout   << baseTrap.getName()
                << "\033[35m values after initializing diamondTraps (hitPoints - energyPoints - attackDamage): \033[0m"
                << baseTrap.getHitPoints() << " - "
                << baseTrap.getEnergyPoints() << " - "
                << baseTrap.getAttackDamage()
                << std::endl;
    
    std::cout << std::endl;

    std::cout   << firstDerivedTrap.getName()
                << "\033[35m values after initializing diamondTraps (hitPoints - energyPoints - attackDamage): \033[0m"
                << firstDerivedTrap.getHitPoints() << " - "
                << firstDerivedTrap.getEnergyPoints() << " - "
                << firstDerivedTrap.getAttackDamage()
                << std::endl;

    std::cout << std::endl;

    std::cout   << secondDerivedTrap.getName()
                << "\033[35m values after initializing diamondTraps (hitPoints - energyPoints - attackDamage): \033[0m"
                << secondDerivedTrap.getHitPoints() << " - "
                << secondDerivedTrap.getEnergyPoints() << " - "
                << secondDerivedTrap.getAttackDamage()
                << std::endl;

    std::cout << std::endl;

    diamondTrap2.attack("Anacletito");
    secondDerivedTrap.takeDamage(diamondTrap2.getAttackDamage());

    std::cout << std::endl;

}