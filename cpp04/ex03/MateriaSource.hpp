#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _materias[4]; //the MateriaSource can know at most 4 Materias

    public:
        MateriaSource(void);
        // MateriaSource(std::string const &type);
        MateriaSource(const MateriaSource &source);
        MateriaSource &operator=(const MateriaSource &source);
        virtual ~MateriaSource(void);
        
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif