#include <iostream>
#include <cstring>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error! Usage: ./prog_name <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    std::fstream originalFile(argv[1]);
   // originalFile.open(argv[1]);
    if (!originalFile.is_open())
    {
        std::cerr << "Error opening original file!" << std::endl;
        return (1);
    }
    std::fstream newFile("test.replace");
    if (!originalFile.is_open())
    {
        std::cerr << "Error creating new file!" << std::endl;
        return (1);
    }
    std::string line;
    while (std::getline (originalFile, line))
    {
        line.find(argv[2]);
        newFile << line << '\n' << std::flush;
    }
    originalFile.close();
    newFile.close();
    return (0);
}