#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <cstring>

class Weapon
{
    private:
        std::string _type;
    public:
        Weapon(std::string weapon);
        ~Weapon();
        std::string getType(void) const;
        void setType(std::string  newType);
};


#endif