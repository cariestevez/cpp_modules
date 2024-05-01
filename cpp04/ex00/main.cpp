#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    std::cout << std::endl;
    
    const Animal* j = new Dog();
    std::cout << std::endl;
    
    const Animal* i = new Cat();
    std::cout << std::endl;
    
    const WrongAnimal* h = new WrongCat();
    std::cout << std::endl;
    
    const WrongCat* g = new WrongCat();
    std::cout << std::endl;
   
    std::cout << meta->getType() << ": ";
    meta->makeSound();
    
    std::cout << j->getType() << ": ";
    j->makeSound();

    std::cout << i->getType() << ": ";
    i->makeSound();

    std::cout << h->getType() << ": ";
    h->makeSound();

    std::cout << g->getType() << ": ";
    g->makeSound();

    std::cout << std::endl;

    delete meta;
    delete j;
    delete i;
    delete h;
    delete g;

    return 0;
}