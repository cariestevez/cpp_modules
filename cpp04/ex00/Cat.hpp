#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
protected:
    std::string type;
public:
    Cat(void);
    Cat(std::string type);
    Cat(const Cat &source);
    Cat &operator=(const Cat &source);
    ~Cat(void);

    virtual void makeSound(void);
};

#endif