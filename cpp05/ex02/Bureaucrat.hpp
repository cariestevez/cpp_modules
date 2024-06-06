#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int               _grade;
        static const int _maxGrade = 1;
        static const int _minGrade = 150;
    public:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };  
        Bureaucrat(void);
        Bureaucrat(const Bureaucrat &source);
        Bureaucrat &operator=(const Bureaucrat &source);
        ~Bureaucrat(void);

        Bureaucrat(std::string name, int  grade);

        int getGrade(void) const;
        const std::string getName(void) const;

        void    incrementGrade(void);
        void    decrementGrade(void);

        void    checkGrade(int grade);
        void    signForm(AForm &form);

        void    executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &output, Bureaucrat const &instance);

#endif