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
    virtual ~Animal(void);

    const std::string getType(void) const;

    virtual void makeSound(void) const;
};

#endif

// Virtual member function = method => decision of which function(from which class) it's called,
// is decided dinamically, not during compilation time.
// It allows the derived class to share a same function with the base class (with different output)
// and this being called insted of always the one of the class it's inheriting from
// Virtual Destructor:
// If a class has a virtual destructor, then when you delete an object through a pointer to the base class, the destructor of the derived class (if any) is also called, in addition to the destructor of the base class.
// This ensures that destructors of derived classes are properly invoked, allowing for proper cleanup of resources and preventing memory leaks.
// Using a virtual destructor is essential when you have a polymorphic base class and you intend to delete objects of derived classes through pointers to the base class.