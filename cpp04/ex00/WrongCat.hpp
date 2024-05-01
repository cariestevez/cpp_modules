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
    virtual ~WrongCat(void);

    const std::string getType(void) const;

    void makeSound(void) const;
};

#endif