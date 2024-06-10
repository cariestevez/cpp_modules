#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(const Intern &source);
        Intern &operator=(const Intern &source);
        virtual ~Intern(void);

        Form *makeForm(const std::string &formName, const std::string &target);
        Form *createShrubberyForm(const std::string &target);
        Form *createRobotomyForm(const std::string &target);
        Form *createPresidentialForm(const std::string &target);
};

#endif