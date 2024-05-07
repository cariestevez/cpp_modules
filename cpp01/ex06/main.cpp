#include "Harl.hpp"

int main (int argc, char **argv)
{
    int     i = 0;
    Harl    harl;

    if (argc != 2)
    {
        std::cout << "Error! Usage: ./harlfilter <COMPLAIN_LEVEL>" << std::endl;
        return (1);
    }

    std::string complains[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    while (i <= 3)
    {
        if (complains[i] == argv[1])
            break;
        i++;
    }

   switch (i) 
   {
        case 0:
            harl.complain(complains[0]);
            break;
        case 1:
            harl.complain(complains[1]);
            break;
        case 2:
            harl.complain(complains[2]);
            break;
        case 3:
            harl.complain(complains[3]);
            break;
        default:
            harl.complain(argv[1]);
            break;
    }

    return 0;
}