#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Anonymous"), _grade(70)
{
	std::cout << "\e[47mBureaucrat::\e[0m Default constructor called for " << _name << std::endl;  
}

Bureaucrat::Bureaucrat(std::string name, int  grade) : _name(name)
{
	std::cout << "\e[47mBureaucrat::\e[0m Parameterized constructor called for " << _name << std::endl;
	checkGrade(grade);
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source) : _name(source._name), _grade(source._grade)
{
	std::cout << "\e[47mBureaucrat::\e[0m Copy constructor called for " << _name << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source)
{
	if (this != &source)
	{
		_grade = source._grade;
	}
	
	std::cout << "\e[47mBureaucrat::\e[0m Assignment operator used for " << _name << std::endl;
	  
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "\e[47mBureaucrat::\e[0m Destructor called for " << _name << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

const std::string Bureaucrat::getName(void) const
{
	return _name;
}

//////////////////////////////////////////////////////////////////////////////////////

void    Bureaucrat::incrementGrade(void)
{
	checkGrade(_grade - 1);
	_grade--;
	std::cout << "\e[47mBureaucrat::\e[0m Grade incremented for " << _name << std::endl;
  
}

void    Bureaucrat::decrementGrade(void)
{
	checkGrade(_grade + 1);
	_grade++;
	std::cout << "\e[47mBureaucrat::\e[0m Grade decremented for " << _name << std::endl;

}

//////////////////////////////////////////////////////////////////////////////////////

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "\e[47mBureaucrat::\e[0m \e[4;31mGrade too high!\e[0m";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "\e[47mBureaucrat::\e[0m \e[4;31mGrade too low!\e[0m";
}

//////////////////////////////////////////////////////////////////////////////////////

void Bureaucrat::checkGrade(int grade)
{
	if (grade >= _maxGrade && grade <= _minGrade)
		return ;
    else if (grade < _maxGrade)
	{
        throw GradeTooHighException();
    }
	else
	{
        throw GradeTooLowException();
    }
}

void    Bureaucrat::signForm(Form &f)
{
	f.beSigned(*this);
}

//////////////////////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &output, Bureaucrat const &instance)
{
    output << instance.getName() << ", bureaucrat grade " << instance.getGrade() << ".";

    return output;
}