#include "Zombie.hpp"

int main(void)
{
    Zombie *dynamicZombie = newZombie("Kizombi");

    randomChump("Chupacabras");
    dynamicZombie->announce();
    delete dynamicZombie;

    return (0);
}