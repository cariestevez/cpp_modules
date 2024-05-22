#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "\e[40mIntern::\e[0m Default constructor called" << std::endl;  
}

Intern::Intern(const Intern &source)
{
	(void)source;
	std::cout << "\e[40mIntern::\e[0m Copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &source)
{	
	(void)source;
	std::cout << "\e[40mIntern::\e[0m Assignment operator used" << std::endl;
	  
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "\e[40mIntern::\e[0m Destructor called" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

Form *Intern::makeForm(const std::string formName, const std::string target)
{
    // Map form names to corresponding form types
    static std::map<std::string, Form*> formTypes;

    // Insert elements into the map
    formTypes["shrubbery creation"] = new ShrubberyCreationForm(target);
    formTypes["robotomy request"] = new RobotomyRequestForm(target);
    formTypes["presidential pardon"] = new PresidentialPardonForm(target);

    // Check if the provided form name exists in the map
    std::map<std::string, Form*>::const_iterator it = formTypes.find(formName);
	if (it != formTypes.end())//if it didn't arrive at the end => coincidence found
	{
        std::cout << "Intern creates " << formName << std::endl;
		it->second->setName(formName);
        // Delete the other form objects not being returned
        for (std::map<std::string, Form*>::iterator deleteIt = formTypes.begin(); deleteIt != formTypes.end(); ++deleteIt)
		{
            if (deleteIt != it)
			{
                delete deleteIt->second;
            }
        }
        return it->second;//it is now evtl. pointing to one of the pairs, so we return the second member of the std::pair type of the map
    } 
	else
	{
        std::cerr << "Error: Form name '" << formName << "' does not exist." << std::endl;
        // Delete all form objects if none match the form name
        for (std::map<std::string, Form*>::iterator deleteIt = formTypes.begin(); deleteIt != formTypes.end(); ++deleteIt)
		{
            delete deleteIt->second;
        }
        return NULL;
    }
	// Form *form;

    // if (formName == "xxx")
	// 	form = new ShrubberyCreationForm(target);
	// else if (formName == "xxx")
	// 	form = new RobotomyRequestForm(target);
	// else if (formName == "xxx")
	// 	form = new PresidentialPardonForm(target);
	// else
	// {
	// 	std::cout << "Error! Form type unknown" << std::endl;
	// 	return NULL;
	// }

	// form->setName(formName);

	// return form;
}