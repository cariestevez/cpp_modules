#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>

class Brain
{
protected:
    std::string _ideas[100];
public:
    Brain(void);
    Brain(const Brain &source);
    Brain &operator=(const Brain &source);
    virtual ~Brain(void);

    bool ideaIsEmpty(int i) const;
    void addIdeaAtIndex(const std::string& idea, int i);
    void getIdeas(void) const;

};

#endif