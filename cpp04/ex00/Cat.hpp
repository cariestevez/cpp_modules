#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
protected:
    std::string _type;
public:
    Cat(void);
    Cat(std::string type);
    Cat(const Cat &source);
    Cat &operator=(const Cat &source);
    ~Cat(void);

    const std::string getType(void) const;

    virtual void makeSound(void) const;
};

#endif