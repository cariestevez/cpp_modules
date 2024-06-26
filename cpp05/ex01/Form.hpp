#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _requiredGradeToSign;
        const int           _requiredGradeToExecute;
        static const int    _maxGrade = 1;
        static const int    _minGrade = 150;

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

        Form(void);
        Form(const Form &source);
        Form &operator=(const Form &source);
        ~Form(void);

        Form(std::string name, int requiredGradeToSign, int requiredGradeToExecute);

        std::string getName(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;
        bool getIsSigned(void) const;   

        void beSigned(Bureaucrat &b);
    
        void checkRequiredGrade(int grade);
};

std::ostream &operator<<(std::ostream &output, Form const &instance);

#endif