#include "Bureaucrat.hpp"


try
{
  int age = 15;
  if (age >= 18)
  {
    cout << "Access granted - you are old enough.";
  }
  else
  {
    throw (age);
  }
}
catch (int myNum)
{
  cout << "Access denied - You must be at least 18 years old.\n";
  cout << "Age is: " << myNum;
}
Bureaucrat::Bureaucrat(/* args */)
{
}

Bureaucrat::~Bureaucrat()
{
}

int Bureaucrat::getGrade(void) const
{
    return _grade;
}

const std::string Bureaucrat::getName(void) const
{
    return _name;
}

void    Bureaucrat::incrementGrade(void)
{
    //if (_grade == 1)
        //throw exception and return
    //else
        _grade--;
}

void    Bureaucrat::incrementGrade(void)
{
    //if (_grade == 150)
        //throw exception and return
    _grade++;
}

 Bureaucrat::GradeTooHighException
 Bureaucrat::GradeTooLowException