#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
protected:
    std::string _type;
public:
    WrongCat(void);
    WrongCat(std::string type);
    WrongCat(const WrongCat &source);
    WrongCat &operator=(const WrongCat &source);
    ~WrongCat(void);

    const std::string getType(void) const;

    virtual void makeSound(void);
};

#endif