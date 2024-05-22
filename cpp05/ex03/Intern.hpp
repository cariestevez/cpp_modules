#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <map>

class Intern
{
    public:
        Intern(void);
        Intern(const Intern &source);
        Intern &operator=(const Intern &source);
        virtual ~Intern(void);

        Form *makeForm(std::string formName, std::string target);
};

#endif