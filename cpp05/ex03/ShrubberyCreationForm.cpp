#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Shrubbery", 145, 137), _target("xxx")
{
	std::cout << "\e[42mShrubberyCreationForm::\e[0m Default constructor called for " << getName() << std::endl;  
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery", 145, 137), _target(target)
{
	std::cout << "\e[42mShrubberyCreationForm::\e[0m Parameterized constructor called for " << getName() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source) : Form(source), _target(source._target)
{
	std::cout << "\e[42mShrubberyCreationForm::\e[0m Copy constructor called for " << getName() << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &source)
{
	if (this != &source)
	{
        Form::operator=(source);
        _target = source._target;
	}
	
	std::cout << "\e[42mShrubberyCreationForm::\e[0m Assignment operator used for " << getName() << std::endl;
	  
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "\e[42mShrubberyCreationForm::\e[0m Destructor called for " << getName() << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    CanBeExecuted(executor);

	std::string fileName = _target + "_shrubbery";
    std::ofstream ofsFile(fileName.c_str());

    if (!ofsFile.is_open())
	{
        std::cerr << "Error: Could not open file " << fileName << " for writing." << std::endl;
        return ;
    }

	ofsFile << "    ooxooo    ooxoo\n";
	ofsFile << "  ooxoxo oo  oxoxoooo\n";
	ofsFile << " oooo xxoxoo ooo oooxx\n";
	ofsFile << " oxo o oxoxo  xoxxoxo\n";
	ofsFile << "  oxo xooxoooo o ooo\n";
	ofsFile << "    ooo'\'oo'\'  /o/oo\n";
	ofsFile << "        '\'  '\'/ /\n";
	ofsFile << "         |   /\n";
	ofsFile << "         |  |\n";
	ofsFile << "         |  |\n";
	ofsFile << "         |  |\n";
	ofsFile << "         |  |\n";
	ofsFile << "  ______/____'\'___\n";

    ofsFile.close();
}