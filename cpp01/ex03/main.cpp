#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");//init of weapon object
        HumanA bob("Bob", club);//its class object gets initialized to the created weapon class (we need its address)
        bob.attack();
        club.setType("some other type of club");//modifies the club object
        bob.attack();//since Bob has a reference (= the exact same object), so it will print the new one
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}