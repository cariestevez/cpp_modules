#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cerr << "Error: could not open file." << std::endl;
    
    else
    {
        std::ifstream inputFile(argv[1]);
        if (!inputFile)
        {
            std::cerr << "Error: could not open file." << std::endl;
            return 1;
        }
        
        inputFile.close();
    }


    return 0;
}