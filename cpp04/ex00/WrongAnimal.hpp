#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal(void);
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &source);
        WrongAnimal &operator=(const WrongAnimal &source);
        virtual ~WrongAnimal(void);

        const std::string getType(void) const;

        void makeSound(void) const;
};

#endif