#ifndef ICE_H
#define ICE_H

class Ice : public AMateria
{
    protected:
        const std::string _type;
    public:
        Ice(void);
        Ice(std::string const &type);
        Ice(const Ice &source);
        Ice &operator=(const Ice &source);
        ~Ice(void);

        virtual Ice *clone(void) const;
        // virtual void use(ICharacter &target);

};

#endif