#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <iostream>
#include <cstring>

class HumanA
{
    private:
        std::string     _name;
        const Weapon    &_weapon;      
    public:
        HumanA(std::string name, const Weapon &weapon);
        ~HumanA();
        
        void attack(void);
};

#endif