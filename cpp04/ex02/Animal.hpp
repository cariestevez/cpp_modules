#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

//Adding a pure virtual function makes the class abstract
//=> it cannot be instantiated directly. It serve as base class for other classes

class AAnimal
{
protected:
    std::string _type;
public:
    AAnimal(void);
    AAnimal(std::string type);
    AAnimal(const AAnimal &source);
    AAnimal &operator=(const AAnimal &source);
    virtual ~AAnimal(void);

    const std::string getType(void) const;

    virtual void makeSound(void) const = 0; //pure virtual function
};

#endif