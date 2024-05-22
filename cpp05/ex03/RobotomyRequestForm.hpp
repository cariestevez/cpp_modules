#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &source);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &source);
        
        virtual ~RobotomyRequestForm();

        virtual void execute(Bureaucrat const &executor) const;
};

#endif