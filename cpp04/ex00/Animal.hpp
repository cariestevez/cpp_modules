#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;
public:
    Animal(void);
    Animal(std::string type);
    Animal(const Animal &source);
    Animal &operator=(const Animal &source);
    ~Animal(void);

    virtual void makeSound(void);
};

#endif