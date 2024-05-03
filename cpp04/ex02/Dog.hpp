#ifndef DOG_H
#define DOG_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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
    virtual void addIdea(const std::string& idea);
    virtual void printIdeas(void) const;
};

#endif
