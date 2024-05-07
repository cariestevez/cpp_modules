#ifndef AMATERIA_HPP
#define AMATERIA_HPP

// #include "unityBuildHeader.hpp"

class ICharacter;

class AMateria
{
    protected:
        const std::string _type;
    public:
        AMateria(void);
        AMateria(std::string const &type);
        AMateria(const AMateria &source);
        AMateria &operator=(const AMateria &source);
        virtual ~AMateria(void);

        std::string const &getType() const; //Returns the materia type
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);

};

#endif