#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
protected:
    std::string type;
public:
    Dog(void);
    Dog(std::string type);
    Dog(const Dog &source);
    Dog &operator=(const Dog &source);
    ~Dog(void);

    virtual void makeSound(void);
};

#endif
