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
        animals[i]->makeSound();//should output Polymorphic behavior
    }

    std::cout << std::endl;

    Cat guachi("guachipRrRrR");
    std::cout << "Type: " << guachi.getType() << std::endl;
    guachi.addIdea("I'm excited about birds");
    Cat guachiCopy = guachi;
    std::cout << "What's in guachi's mind?" << std::endl;
    guachi.printIdeas();
    std::cout << "What's in guachi copy's mind?" << std::endl;
    guachiCopy.printIdeas();
    guachiCopy.addIdea("My best friend is actually a bird");
    guachi.addIdea("I just want to play with them");
    std::cout << "What's in guachi's mind?" << std::endl;
    guachi.printIdeas();
    std::cout << "What's in guachi copy's mind?" << std::endl;
    guachiCopy.printIdeas();

    std::cout << std::endl;

    Animal *aDog = new Dog("doggo");
    aDog->addIdea("I'm a dog");
    aDog->printIdeas();
    //Animal *dogCopy = aDog;//just saving address of aDog ->leak
    //using the copy constructor:
    //*static_cast<Dog*>(aDog) dereferences aDog to obtain the Dog object it points to,
    //and then passes this object as an argument to the copy constructor of Dog,
    //creating a new Dog object that is a deep copy of the original one
    Animal *dogCopy = new Dog(*static_cast<Dog*>(aDog));
    //Alternatively, if dogCopy is already initialized, using the copy assignment operator:
    //*static_cast<Dog*>(dogCopy) = *static_cast<Dog*>(aDog);
    //Here, *static_cast<Dog*>(dogCopy) and *static_cast<Dog*>(aDog) dereference dogCopy and aDog respectively
    //to obtain the Dog objects they point to,
    //and then the copy assignment operator of Dog is invoked to copy the state of the source Dog object into the destination Dog object.
    //This updates the state of dogCopy with the state of the Dog object pointed to by aDog, effectively performing a deep copy
    delete aDog;
    dogCopy->printIdeas();
    delete dogCopy;

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

//Shallow copy of an object: copies all of the member field values
//If the fields contain references to dynamically allocated memory,
//the memory addresses will be copied, not the actual data.
//Deep copy: copies everything, including dynamically allocated memory,
//ensuring that the copied object is fully independent of the original.