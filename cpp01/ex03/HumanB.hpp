#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <iostream>
#include <cstring>

class HumanB
{
    private:
        std::string _name;
        
    public:
        HumanB(std::string name);
        ~HumanB();
        void attack(void);
        void setWeapon(Weapon weapon);

};

#endif