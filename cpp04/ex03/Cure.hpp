#ifndef CURE_HPP
#define CURE_HPP

// #include "AMateria.hpp"
// #include "unityBuildHeader.hpp"

class Cure : public AMateria
{
    protected:
        const std::string _type;
    public:
        Cure(void);
        Cure(std::string const &type);
        Cure(const Cure &source);
        Cure &operator=(const Cure &source);
        ~Cure(void);

        virtual Cure *clone(void) const;// returns a new instance of the same type
        virtual void use(ICharacter &target);
};

#endif