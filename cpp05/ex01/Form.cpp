#include "Form.hpp"

Form::Form(void) : _name("wtf896"), _isSigned(false)//, _requiredGradeToSign(0), _requiredGradeToExecute(0)
{
	std::cout << "\e[46mForm::\e[0m Default constructor called for " << _name << std::endl;  
}

Form::Form(std::string name, int requiredGradeToSign, int requiredGradeToExecute) : _name(name),  _isSigned(false), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute)
{
	std::cout << "\e[46mForm::\e[0m Parameterized constructor called for " << _name << std::endl;
	checkGrade(_requiredGradeToSign);
	checkGrade(_requiredGradeToExecute);
}

Form::Form(const Form &source) : _name(source._name), _isSigned(source._isSigned), _requiredGradeToSign(source._requiredGradeToSign), _requiredGradeToExecute(source._requiredGradeToExecute)
{
	std::cout << "\e[46mForm::\e[0m Copy constructor called for " << _name << std::endl;
}

Form &Form::operator=(const Form &source)
{
	if (this != &source)
	{
		(std::string)_name = source._name;
		_isSigned = source._isSigned;
		_requiredGradeToSign = (const int)source._requiredGradeToSign;
		(int)_requiredGradeToExecute = source._requiredGradeToExecute;
	}
	
	std::cout << "\e[46mForm::\e[0m Assignment operator used for " << _name << std::endl;
	  
	return (*this);
}

Form::~Form(void)
{
	std::cout << "\e[46mForm::\e[0m Destructor called for " << _name << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

const std::string Form::getName(void) const
{
	return _name;
}

const int Form::getRequiredGradeToSign(void) const
{
	return _requiredGradeToSign;
}

const int Form::getRequiredGradeToExecute(void) const
{
	return _requiredGradeToExecute;
}

bool Form::getIsSigned(void) const
{
    return _isSigned;
}


//////////////////////////////////////////////////////////////////////////////////////

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "\e[4;31mGrade too high!\e[0m";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "\e[4;31mGrade too low!\e[0m";
}

//////////////////////////////////////////////////////////////////////////////////////

void checkGrade(int grade)
{
    if (grade >= _maxGrade && grade <= _minGrade)
		return ;
    else if (grade < _minGrade)
	{
        throw GradeTooHighException();
    }
	else
	{
        throw GradeTooLowException();
    }
}