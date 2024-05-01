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

    return 0;
}