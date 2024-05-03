#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    const AAnimal* j = new Dog();//concrete class derived from the abstract class AAnimal
    const AAnimal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    // std::cout << std::endl;

    // std::cout << "testing abstract" << std::endl;

    // const AAnimal* pureAnimal = new AAnimal();//attempt to create an instance of the abstract class
    // pureAnimal->getType();
    // delete pureAnimal;

    return 0;
}

//Abstract classes:
//https://www.ibm.com/docs/en/zos/2.4.0?topic=only-abstract-classes-c