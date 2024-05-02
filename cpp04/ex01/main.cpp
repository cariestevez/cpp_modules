#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

// In your main function, create and fill an array of Animal objects. Half of it will
// be Dog objects and the other half will be Cat objects. At the end of your program
// execution, loop over this array and delete every Animal. You must delete directly dogs
// and cats as Animals. The appropriate destructors must be called in the expected order.
// Don’t forget to check for memory leaks.
// A copy of a Dog or a Cat mustn’t be shallow. Thus, you have to test that your copies
// are deep copies!

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout << std::endl;

    Animal *animals[4];//pointer to the array of base class elements
    for (int i = 0; i < 4; i++)
    {
        if (i < 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << std::endl;

    for (int i = 0; i < 4; i++)
    {
        animals[i]->makeSound(); // should output Polymorphic behavior
    }

    std::cout << std::endl;

    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }

    return 0;
}

//Polymorphism refers to the ability of different objects to be treated
//as instances of the same class through a common interface.
//Achieved through inheritance and virtual functions.
//by doing animals[i] = Dog(); or animals[i] = Cat(); polymorphism gets lost
//-> makeSound() from animal class overrides makeSound() from specific animals
//to avoid object slicing: use pointer and dynamic memory allocation
