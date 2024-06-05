#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal(void);
        Animal(std::string type);
        Animal(const Animal &source);
        Animal &operator=(const Animal &source);
        virtual ~Animal(void);//*

        const std::string getType(void) const;

        virtual void makeSound(void) const;
        virtual void addIdea(const std::string& idea);
        virtual void printIdeas(void) const;

};

#endif

//being virtual, ensures that the destructors of the derived classes are called properly when deleting objects through a base class pointer
//int main() {
//     Base* ptr = new Derived();
//     delete ptr;
//     return 0;
// }
//in this case, without a virtual destructor, only the base destructor would be called
//when deleting the ptr from the main, not the derived one, creating leaks