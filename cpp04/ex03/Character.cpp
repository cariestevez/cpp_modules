
// The Character possesses an inventory of 4 slots, which means 4 Materias at most.
// The inventory is empty at construction. They equip the Materias in the first empty slot
// they find. This means, in this order: from slot 0 to slot 3. In case they try to add
// a Materia to a full inventory, or use/unequip an unexisting Materia, don’t do anything
// (but still, bugs are forbidden). The unequip() member function must NOT delete the
// Materia!
// Handle the Materias your character left on the floor as you like.
// Save the addresses before calling unequip(), or anything else, but
// don’t forget that you have to avoid memory leaks.
// The use(int, ICharacter&) member function will have to use the Materia at the
// slot[idx], and pass the target parameter to the AMateria::use function.
//Your character’s inventory will be able to support any type of
//AMateria
// Your Character must have a constructor taking its name as a parameter. Any copy
// (using copy constructor or copy assignment operator) of a Character must be deep.
// During copy, the Materias of a Character must be deleted before the new ones are added
// to their inventory. Of course, the Materias must be deleted when a Character is destroyed.

equip(tmp);

use(0, *bob);
