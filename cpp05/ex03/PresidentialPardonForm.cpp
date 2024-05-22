#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("Presidential Pardon", 25, 5), _target("xxx")
{
	std::cout << "\e[45mPresidentialPardonForm::\e[0m Default constructor called for " << getName() << std::endl;  
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon", 25, 5), _target(target)
{
	std::cout << "\e[45mPresidentialPardonForm::\e[0m Parameterized constructor called for " << getName() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &source) : Form(source), _target(source._target)
{
	std::cout << "\e[45mPresidentialPardonForm::\e[0m Copy constructor called for " << getName() << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &source)
{
	if (this != &source)
	{
        Form::operator=(source);
        _target = source._target;
	}
	
	std::cout << "\e[45mPresidentialPardonForm::\e[0m Assignment operator used for " << getName() << std::endl;
	  
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "\e[45mPresidentialPardonForm::\e[0m Destructor called for " << getName() << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    CanBeExecuted(executor);

    std::cout << "\e[0;95m" << _target << " has been pardoned by Zaphod Beeblebrox.\e[0m" << std::endl;
}