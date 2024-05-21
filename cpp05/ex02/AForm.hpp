#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _requiredGradeToSign;
        const int           _requiredGradeToExecute;
        static const int    _maxGrade = 1;
        static const int    _minGrade = 50;

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

        AForm(void);
        AForm(const AForm &source);
        AForm &operator=(const AForm &source);
        virtual ~AForm(void);

        AForm(std::string name, int requiredGradeToSign, int requiredGradeToExecute);

        std::string getName(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;
        bool getIsSigned(void) const;   

        void beSigned(Bureaucrat &b);
    
        void checkRequiredGrade(int grade);

        virtual void execute(Bureaucrat const & executor) const = 0;//This declaration means that the execute function has no implementation in the abstract class AForm. Consequently, any class that derives from AForm must provide its own implementation of the execute function. Otherwise, the derived class will also be considered abstract and cannot be instantiated. By declaring execute as a pure virtual function, you are establishing a contract that any derived class must fulfill. This ensures that all derived classes provide specific behavior for the execute function
};

std::ostream &operator<<(std::ostream &output, AForm const &instance);

#endif