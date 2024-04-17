#include <iostream>
#include <string>
#include <fstream>

void    ftReplace(std::string &line, const std::string &s1, const std::string &s2)
{
    size_t i = 0;

    while ((i = line.find(s1)) != std::string::npos)//if occurrence found, save position and substitute for s2
    {   
        line.erase(i, s1.length());
        line.insert(i, s2);
    }
}

void    replaceStringInFile(const std::string &file, const std::string &s1, const std::string &s2)
{
    std::ifstream    inputFile(file);//opens file in input mode (read). inputFile its equivalent of a fd
    if (!inputFile)
    {
        std::cerr << "Error opening input file!" << file << std::endl;
        return ;
    }

    std::string     outputFileName = file + ".replace";
    std::ofstream    outputFile(outputFileName);//creates and opens in output mode (write)
    if (!outputFile)
    {
        std::cerr << "Error creating new file!" << std::endl;
        inputFile.close();
        return ;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        ftReplace(line, s1, s2);
        outputFile << line;
        if (!inputFile.eof())
           outputFile << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return ;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error! Usage: ./prog_name <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty() || s2.empty())
    {
        std::cout << "Error! Empty string passed as argument!" << std::endl;
        return (1);
    }
 
    replaceStringInFile(argv[1], s1, s2);
    
    return (0);
}
