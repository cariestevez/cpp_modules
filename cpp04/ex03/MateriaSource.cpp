#include "unityBuildHeader.hpp"

// In a nutshell, your MateriaSource must be able to learn "templates" of Materias to
// create them when needed. Then, you will be able to generate a new Materia using just
// a string that identifies its type.

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        _materias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        delete _materias[i];
}

// learnMateria(AMateria*)
// Copies the Materia passed as a parameter and store it in memory so it can be cloned
// later. Like the Character, the MateriaSource can know at most 4 Materias.
// They are not necessarily unique.
void MateriaSource::learnMateria(AMateria *materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_materias[i])
        {
            _materias[i] = materia; //materia->clone();
            return ;
        }
        // else
        //     std::cout << "Index " << i << " has " << _materias[i]->getType() << std::endl;
    }
}

// • createMateria(std::string const &)
// Returns a new Materia. The latter is a copy of the Materia previously learned by
// the MateriaSource whose type equals the one passed as parameter. Returns 0 if
// the type is unknown.
AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }

    return 0;
}