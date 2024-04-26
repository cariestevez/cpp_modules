#include "ClapTrap.hpp"

int main()
{
    ClapTrap firstTrap = ClapTrap("Pepe");
    ClapTrap secondTrap = ClapTrap("Anacleto");

    firstTrap.attack("Anacleto");
    secondTrap.takeDamage(firstTrap.getAttackDamage());
    secondTrap.beRepaired(5);

    firstTrap.setAttackDamage(12);
    firstTrap.attack("Anacleto");
    secondTrap.takeDamage(firstTrap.getAttackDamage());
    firstTrap.attack("Anacleto");
    secondTrap.takeDamage(firstTrap.getAttackDamage());
}