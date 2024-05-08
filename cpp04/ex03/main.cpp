#include "unityBuildHeader.hpp"

int main()
{
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
    // me->unequip(0);
    // me->unequip(1);
    me->equip(tmp);
    me->use(0, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}

// int main()
// {
//     IMateriaSource* src = new MateriaSource(); // Create a new MateriaSource object and assign its address to src pointer
//     src->learnMateria(new Ice()); // Learn a new Ice materia and store it in the MateriaSource (storing address to Ice pointer)
//     src->learnMateria(new Cure()); // Learn a new Cure materia and store it in the MateriaSource
    
//     ICharacter* me = new Character("me"); // Create a new Character object named "me" and assign its address to me pointer
//     AMateria* tmp; // Declare a pointer tmp to store the created materia
//     tmp = src->createMateria("ice"); // Create an Ice materia using the MateriaSource (cloning the materia learnt by src and stored in _materias[0] in this case (ice is at position 0))
//     //createMateria returned a ptr that is now stored in tmp
//     me->equip(tmp); // and equip it to "me" (saving the address of the pointer)
//     //tmp ptr saved in me character's inventory
//     tmp = src->createMateria("cure"); // Create a Cure materia using the MateriaSource
//     me->equip(tmp); // and equip it to "me"
    
//     ICharacter* bob = new Character("bob"); // Create a new Character object named "bob" and assign its address to bob pointer
    
//     me->use(0, *bob);  // Use the first materia in "me"'s inventory on "bob"
//     me->use(1, *bob);  // Use the second materia in "me"'s inventory on "bob"
//     // me->unequip(0); // (deleting the stored address to the first materia saved in the inventory)
//     std::cout << std::endl;

//     tmp = src->createMateria("whatever");
//     me->equip(tmp); // trying to save the same ptr into the inventoy
//     me->use(0, *bob); // (nothing happens since nothing is stored anymore)
//     me->use(1, *bob);


//     // src->learnMateria(new Cure());
//     // tmp = src->createMateria("cure");
//     // me->equip(tmp); // equips the first empty space in the inventory
//     // me->equip(tmp);
//     // me->use(0, *bob);
//     // me->use(1, *bob);
//     std::cout << "before deleting" << std::endl;
//     delete bob; // Delete the "bob" character object
//     delete me; // Delete the "me" character object
//     delete src; // Delete the MateriaSource object

//     std::cout << "after deleting" << std::endl;



//     {
// 		std::cout << "\033[1;32mSome other tests\033[0m" << std::endl;
// 		IMateriaSource* src2 = new MateriaSource();
// 		src2->learnMateria(new Ice());
// 		src2->learnMateria(new Cure());
// 		src2->learnMateria(new Cure());
// 		src2->learnMateria(new Ice());

// 		Character*	anon = new Character();

// 		AMateria*	tmp2;
		
// 		tmp2 = src2->createMateria("ice");
// 		anon->equip(tmp2);
// 		anon->unequip(0);
		
// 		Character*	gilles = new Character("Gilles");
// 		anon->use(0, *gilles);
// 		anon->use(120, *gilles);

// 		delete gilles;
// 		delete anon;
// 		delete src2;
// 	}
    
//     return 0;
// }