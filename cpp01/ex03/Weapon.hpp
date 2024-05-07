#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <cstring>

class Weapon
{
    private:
        std::string _type;
    public:
        Weapon(const char *initialType);
        ~Weapon();
        const std::string &getType(void) const;
        void setType(const std::string  &newType);
};


#endif