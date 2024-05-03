#ifndef AANIMAL_H
#define AANIMAL_H

#include <iostream>
#include <string>


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
    virtual void addIdea(const std::string& idea);
    virtual void printIdeas(void) const;
};

#endif

//Adding at least 1 pure virtual function makes the class abstract
//=> it cannot be instantiated directly. It serves as base class for other classes