//#include "unityBuildHeader.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource(); // Create a new MateriaSource object and assign its address to src pointer
    src->learnMateria(new Ice()); // Learn a new Ice materia and store it in the MateriaSource
    src->learnMateria(new Cure()); // Learn a new Cure materia and store it in the MateriaSource
    
    ICharacter* me = new Character("me"); // Create a new Character object named "me" and assign its address to me pointer
    AMateria* tmp; // Declare a pointer tmp to store the created materia
    tmp = src->createMateria("ice"); // Create an Ice materia using the MateriaSource
    me->equip(tmp); // and equip it to "me"
    tmp = src->createMateria("cure"); // Create a Cure materia using the MateriaSource
    me->equip(tmp); // and equip it to "me"
    
    ICharacter* bob = new Character("bob"); // Create a new Character object named "bob" and assign its address to bob pointer
    
    me->use(0, *bob);  // Use the first materia in "me"'s inventory on "bob"
    me->use(1, *bob);  // Use the second materia in "me"'s inventory on "bob"
    
    delete bob; // Delete the "bob" character object
    delete me; // Delete the "me" character object
    delete src; // Delete the MateriaSource object
    
    return 0;
}