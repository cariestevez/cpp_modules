#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *_brain;
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
