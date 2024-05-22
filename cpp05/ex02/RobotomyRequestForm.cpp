#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy", 72, 45), _target("xxx")
{
	std::cout << "\e[43mRobotomyRequestForm::\e[0m Default constructor called for " << getName() << std::endl;  
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), _target(target)
{
	std::cout << "\e[43mRobotomyRequestForm::\e[0m Parameterized constructor called for " << getName() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source) : AForm(source), _target(source._target)
{
	std::cout << "\e[43mRobotomyRequestForm::\e[0m Copy constructor called for " << getName() << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &source)
{
	if (this != &source)
	{
        AForm::operator=(source);
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

    // Seed random number generator
    // By default std::rand() will produce the same sequence of numbers each time the program is run
    // To get a different sequence of nums everytime, seed the generator with a value that changes, like the current time.
    std::srand(std::time(0));

    std::cout << "\e[0;93mBzzbbrrrzz... ";

    // Simulate a 50% chance of success
    if (std::rand() % 2)
    {
        std::cout << _target << " has been robotomized\e[0m" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed. " << _target << " escaped!\e[0m" << std::endl;
    }
}