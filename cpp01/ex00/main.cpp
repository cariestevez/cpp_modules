#include "Zombie.hpp"

int main(void)
{
    randomChump("Chupacabras");
    Zombie *dynamicZombie = newZombie("Kizombi");

    dynamicZombie->announce();
    delete dynamicZombie;

    return (0);
}