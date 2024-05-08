#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat : public std::exception
{
private:
    const std::string _name;
    int _grade;
    static const int max_grade = 1;
    static const int min_grade = 150;
public:
    class GradeTooHighException
    class GradeTooLowException
    Bureaucrat(/* args */);
    ~Bureaucrat();

    int getGrade(void) const;
    const std::string getName(void) const;

    void    incrementGrade(void);
    void    decrementGrade(void);
};

#endif