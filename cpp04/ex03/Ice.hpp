#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"
#include <iostream>
#include <string>

class Ice
{
    protected:
        const std::string _type;
    public:
        Ice(void);
        Ice(std::string const &type);
        Ice(const Ice &source);
        Ice &operator=(const Ice &source);
        ~Ice(void);

        Ice *clone(const Ice *source);
        void use(ICharacter& target);

};

#endif