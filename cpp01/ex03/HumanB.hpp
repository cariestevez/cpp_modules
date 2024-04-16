#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <iostream>
#include <cstring>

class HumanB
{
    private:
        std::string     _name;
        const Weapon    *_weapon;//_weapon has to be a ptr so it can be initialized (to null) since we're not allowed to init it in the constructor 
        
    public:
        HumanB(std::string name);//only takes the name parameter, so _weapon has to be init to null (can only be done with a ptr)
        //~HumanB();
        
        void setWeapon(const Weapon &weaponObject);//passing address of the weaponObject initialized in the main
        void attack(void);

};

#endif