#include "Zombie.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error! Usage: ./MoarBrainz! horde_size" << std::endl;
        return (1);
    }

    int members = std::atoi(argv[1]);
    Zombie *dynamicZombieHorde = zombieHorde(members, "theTribe");

    for (int i = 0; i < members; i++)
        dynamicZombieHorde[i].announce();

    delete [] dynamicZombieHorde;

    return (0);
}  