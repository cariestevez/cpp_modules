#include "unityBuildHeader.hpp"

// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
    
//     ICharacter* me = new Character("me");
    
//     AMateria* tmp;
//     tmp = src->createMateria("ice");//allocates and saves in MateriaSource _materias[i]
//     me->equip(tmp);
//     tmp = src->createMateria("cure");//allocates and saves in MateriaSource _materias[i]
//     me->equip(tmp);//saves a copy of the ptr in the character's _inventory[i]

//     ICharacter* bob = new Character("bob");
    
//     me->use(0, *bob);
//     me->use(1, *bob);
//     me->unequip(0);
//     me->unequip(1);

//     delete bob;
//     delete me;
//     delete src;

//     return 0;
// }
int main(void)
{

	{
		//Example provided
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		//Testing what happens when the materia source tries to learn more than 4 materias
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		delete src;
	}
	{
		//A character learns 4 materias, unequip ones, learns a different one and uses some materias, some of them don't exist
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("Cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->unequip(0);
		me->unequip(0);
		me->unequip(5);
		me->use(0, *bob);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->use(0, *bob);
		me->use(5, *bob);
		delete bob;
		delete me;
		delete src;
	}
}