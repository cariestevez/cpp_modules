#include "unityBuildHeader.hpp"

// The Character possesses an inventory of 4 slots, which means 4 Materias at most.
// The inventory is empty at construction.
Character::Character(void) : _name("no_name"), _unequipedMateriasCount(0)
{
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
    for (int i = 0; i < 1000; ++i)
        _unequipedMaterias[i] = NULL;
    // std::cout << "Character:: Default constructor called for " << _name << std::endl;
}

// Your Character must have a constructor taking its name as a parameter.
Character::Character(std::string name) : _name(name), _unequipedMateriasCount(0)
{
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
    for (int i = 0; i < 1000; ++i)
        _unequipedMaterias[i] = NULL;
    // std::cout << "Character:: Parameterized constructor called for " << _name << std::endl;
}

// Any copy (using copy constructor or copy assignment operator) of a Character must be deep.
// During copy, the Materias of a Character must be deleted before the new ones are added
// to their inventory.
Character::Character(const Character &source) : _name(source._name)
{
    for (int i = 0; i < 4; i++)
    {
        if ((source._inventory)[i])
        {
            _inventory[i] = source._inventory[i]->clone();
        }
        else
            _inventory[i] = NULL;
    }

    // std::cout << "Character:: Default constructor called for " << _name << std::endl;
}

Character &Character::operator=(const Character &source)
{
    if (this != &source)
    {
        _name = source._name;
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
                delete _inventory[i];
            if (source._inventory[i])
                _inventory[i] = (source._inventory[i])->clone();
            else
                _inventory[i] = NULL;
        }
        for (int i = 0; i < 1000; i++)
        {
            if (_unequipedMaterias[i])
                delete _unequipedMaterias[i];
            if (source._unequipedMaterias[i])
                _unequipedMaterias[i] = (source._unequipedMaterias[i])->clone();
            else
                _unequipedMaterias[i] = NULL;
            _unequipedMateriasCount = source._unequipedMateriasCount;
        }
    }
	
    // std::cout << "Character:: Assignment operator used for " << _name << std::endl;
	
    return (*this);
}

//the Materias must be deleted when a Character is destroyed.
Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
       delete _inventory[i];
       _inventory[i] = NULL;
    }
    for (int i = 0; i < 1000; i++)
    {
        if (_unequipedMaterias[i])
        {
            delete _unequipedMaterias[i];
            _unequipedMaterias[i] = NULL;
        }
    }

    // std::cout << "Character:: Destructor called for " << _name << std::endl;
}

///////////////////////////////////////////////////////////////////////////////

std::string const &Character::getName() const
{
    return _name;
}

///////////////////////////////////////////////////////////////////////////////

//They equip the Materias in the first empty slot they find.
//This means, in this order: from slot 0 to slot 3.
//In case they try to add a Materia to a full inventory, or use/unequip an unexisting Materia, don’t do anything
// (but still, bugs are forbidden).
void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == NULL && m != NULL)
        {
            // std::cout << "equip with materia " << m->getType() << std::endl;
            _inventory[i] = m;
            return ;
        }
    }
}

//The unequip() member function must NOT delete the Materia!
// Handle the Materias your character left on the floor as you like.
// Save the addresses before calling unequip(), or anything else, but
// don’t forget that you have to avoid memory leaks.
void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
    {
        //try to save address to delete later before exiting
        _unequipedMaterias[_unequipedMateriasCount++] = _inventory[idx];
        if (_unequipedMateriasCount == 1000)
        {
            _unequipedMateriasCount = 0;
            delete _unequipedMaterias[_unequipedMateriasCount];
            _unequipedMaterias[_unequipedMateriasCount] = NULL;
        }
        _inventory[idx] = NULL;
    }
}

// The use(int, ICharacter&) member function will have to use the Materia at the
// slot[idx], and pass the target parameter to the AMateria::use function.
void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
    {
        // std::cout << "in character use idx = " << idx << std::endl;
        _inventory[idx]->use(target);
    }
}
