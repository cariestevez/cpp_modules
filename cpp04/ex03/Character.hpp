#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria    *_inventory[4]; //Your character’s inventory will be able to support any type of AMateria
    public:
        Character(void);
        Character(std::string name);
        Character(const Character &source);
        Character &operator=(const Character &source);
        ~Character();
        
        virtual std::string const & getName() const;

        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif