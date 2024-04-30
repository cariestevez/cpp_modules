#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string _type;
public:
    Animal(void);
    Animal(std::string type);
    Animal(const Animal &source);
    Animal &operator=(const Animal &source);
    ~Animal(void);

    const std::string getType(void) const;

    virtual void makeSound(void) const;
};

#endif