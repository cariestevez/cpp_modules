#ifndef ZOMBIE_H
# define ZOMBIE_H
#include <iostream>
#include <string>
#include <sstream>

class Zombie
{
    private:
        std::string    _name;
    
    public:
        Zombie(void);
        ~Zombie(void);

        void announce(void);

        void rename(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif