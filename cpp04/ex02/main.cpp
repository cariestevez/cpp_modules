#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

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
