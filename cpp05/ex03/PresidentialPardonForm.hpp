#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &source);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &source);
        
        virtual ~PresidentialPardonForm();

        virtual void execute(Bureaucrat const &executor) const;
};

#endif