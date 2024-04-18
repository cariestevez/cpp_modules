#include "Harl.hpp"

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error! Usage: ./harl <complain_level>" << std::endl;
        std::cout << "Complain levels are:\nDEBUG\nINFO\nWARNING\nERROR" << std::endl;
        return (1);
    }

    Harl    harl;

    harl.complain(argv[1]);
   //harl.complain("INFO");
   //harl.complain("WARNING");
   //harl.complain("ERROR");

    return 0;
}