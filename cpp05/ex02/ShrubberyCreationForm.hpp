#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &source);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &source);
        
        virtual ~ShrubberyCreationForm();

        virtual void execute(Bureaucrat const &executor) const;
};

#endif