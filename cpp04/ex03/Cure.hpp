#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"
#include <iostream>
#include <string>

class Cure
{
    protected:
        const std::string _type;
    public:
        Cure(void);
        Cure(std::string const &type);
        Cure(const Cure &source);
        Cure &operator=(const Cure &source);
        ~Cure(void);

        Cure *clone(const Cure *source);// returns a new instance of the same type
        void use(ICharacter& target);
};

#endif