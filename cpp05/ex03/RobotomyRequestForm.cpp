#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Robotomy", 72, 45), _target("xxx")
{
	std::cout << "\e[43mRobotomyRequestForm::\e[0m Default constructor called for " << getName() << std::endl;  
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy", 72, 45), _target(target)
{
	std::cout << "\e[43mRobotomyRequestForm::\e[0m Parameterized constructor called for " << getName() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source) : Form(source), _target(source._target)
{
	std::cout << "\e[43mRobotomyRequestForm::\e[0m Copy constructor called for " << getName() << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &source)
{
	if (this != &source)
	{
        Form::operator=(source);
        _target = source._target;
	}
	
	std::cout << "\e[43mRobotomyRequestForm::\e[0m Assignment operator used for " << getName() << std::endl;
	  
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "\e[43mRobotomyRequestForm::\e[0m Destructor called for " << getName() << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    CanBeExecuted(executor);

    std::cout << "\e[0;93mBzzbbrrrzz... ";

    if (std::rand() % 2)
    {
        std::cout << _target << " has been robotomized\e[0m" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed. " << _target << " escaped!\e[0m" << std::endl;
    }
}