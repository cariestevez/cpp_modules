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
    //Brain(std::string type);
    Brain(const Brain &source);
    Brain &operator=(const Brain &source);
    virtual ~Brain(void);
};

#endif