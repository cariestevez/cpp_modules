#ifndef CAT_H
#define CAT_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
    Brain *_brain;
protected:
    std::string _type;
public:
    Cat(void);
    Cat(std::string type);
    Cat(const Cat &source);
    Cat &operator=(const Cat &source);
    virtual ~Cat(void);

    const std::string getType(void) const;

    virtual void makeSound(void) const;
    virtual void addIdea(const std::string& idea);
    virtual void printIdeas(void) const;
};

#endif