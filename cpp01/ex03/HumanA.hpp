#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <iostream>
#include <cstring>

class HumanA
{
    private:
        std::string _name;
        Weapon      weapon;
        
    public:
        HumanA(std::string name, Weapon weapon);
        ~HumanA();
        void attack(void);
};

#endif