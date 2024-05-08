#include "unityBuildHeader.hpp"

// MateriaSource must be able to learn "templates" of Materias to
// create them when needed. Then, you will be able to generate a new Materia using just
// a string that identifies its type.
MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        _materias[i] = NULL;
}

// MateriaSource(std::string const &type);

MateriaSource::MateriaSource(const MateriaSource &source)
{
    for (int i = 0; i < 4; i++)
    {
        delete _materias[i];
        _materias[i] = source._materias[i]->clone();
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &source)
{
    if (this != &source)
    {
        for (int i = 0; i < 4; i++)
            _materias[i] = source._materias[i]->clone();
    }
	
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        delete _materias[i];
        _materias[i] = NULL;
    }
}

// learnMateria(AMateria*)
// Copies the Materia passed as a parameter and store it in memory so it can be cloned
// later. Like the Character, the MateriaSource can know at most 4 Materias.
// They are not necessarily unique.
void MateriaSource::learnMateria(AMateria *materia)//stores address of the ptr
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] == NULL)
        {
            _materias[i] = materia; //materia->clone();
            return ;
        }
        // else
        //     std::cout << "Index " << i << " has " << _materias[i]->getType() << std::endl;
    }
    // /delete materia;
}

// • createMateria(std::string const &)
// Returns a new Materia. The latter is a copy of the Materia previously learned by
// the MateriaSource whose type equals the one passed as parameter. Returns 0 if
// the type is unknown.
AMateria *MateriaSource::createMateria(std::string const &type)// goes to ptr address and clones object
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }

    return 0;
}