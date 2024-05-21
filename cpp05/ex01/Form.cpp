#include "Form.hpp"

Form::Form(void) : _name("default"), _isSigned(false), _requiredGradeToSign(70), _requiredGradeToExecute(1)
{
	std::cout << "\e[46mForm::\e[0m Default constructor called for " << _name << std::endl;  
}

Form::Form(std::string name, int requiredGradeToSign, int requiredGradeToExecute) : _name(name),  _isSigned(false), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute)
{
	std::cout << "\e[46mForm::\e[0m Parameterized constructor called for " << _name << std::endl;
	checkRequiredGrade(_requiredGradeToSign);
	checkRequiredGrade(_requiredGradeToExecute);
}

Form::Form(const Form &source) : _name(source._name + "_copy"), _isSigned(source._isSigned), _requiredGradeToSign(source._requiredGradeToSign), _requiredGradeToExecute(source._requiredGradeToExecute)
{
	std::cout << "\e[46mForm::\e[0m Copy constructor called for " << _name << std::endl;
}

Form &Form::operator=(const Form &source)
{
	if (this != &source)
	{
		// (std::string)_name = source._name;
		_isSigned = source._isSigned;
		// (int)_requiredGradeToSign = source._requiredGradeToSign;
		// (int)_requiredGradeToExecute = source._requiredGradeToExecute;
	}
	
	std::cout << "\e[46mForm::\e[0m Assignment operator used for " << _name << std::endl;
	  
	return (*this);
}

Form::~Form(void)
{
	std::cout << "\e[46mForm::\e[0m Destructor called for " << _name << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

std::string Form::getName(void) const
{
	return _name;
}

int Form::getGradeToSign(void) const
{
	return _requiredGradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return _requiredGradeToExecute;
}

bool Form::getIsSigned(void) const
{
    return _isSigned;
}


//////////////////////////////////////////////////////////////////////////////////////

const char *Form::GradeTooHighException::what() const throw()
{
    return "\e[46mForm::\e[0m \e[4;31mGrade too high!\e[0m";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "\e[46mForm::\e[0m \e[4;31mGrade too low!\e[0m";
}

//////////////////////////////////////////////////////////////////////////////////////

void Form::checkRequiredGrade(int grade)
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

//////////////////////////////////////////////////////////////////////////////////////

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _requiredGradeToSign)
	{
		std::cout << b.getName() << " couldn't sign " << getName() << " because this bureaucrat is not autorized" << std::endl;
		throw GradeTooLowException();
	}
	if (_isSigned == true)
		std::cout << b.getName() << " couldn't sign " << getName() << " because it's already signed" << std::endl;
	else if (b.getGrade() <= _requiredGradeToSign && _isSigned == false)
	{
		_isSigned = true;
		std::cout << b.getName() << " signed " << getName() << std::endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &output, Form const &instance)
{
    output << "Form: " << instance.getName() << "\nSigned: " << instance.getIsSigned() << "\nRequired Grade to Sign: " << instance.getGradeToSign() << "\nRequired Grade to Execute: " << instance.getGradeToExecute();
   
    return output;
}