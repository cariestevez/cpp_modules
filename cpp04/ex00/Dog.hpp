#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
    protected:
        std::string _type;
    public:
        Dog(void);
        Dog(std::string type);
        Dog(const Dog &source);
        Dog &operator=(const Dog &source);
        virtual ~Dog(void);

        const std::string getType(void) const;

        virtual void makeSound(void) const;
};

#endif
