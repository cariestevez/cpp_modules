#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _isSigned(false), _requiredGradeToSign(70), _requiredGradeToExecute(1)
{
	std::cout << "\e[46mAForm::\e[0m Default constructor called for " << _name << std::endl;  
}

AForm::AForm(std::string name, int requiredGradeToSign, int requiredGradeToExecute) : _name(name),  _isSigned(false), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute)
{
	std::cout << "\e[46mAForm::\e[0m Parameterized constructor called for " << _name << std::endl;
	checkRequiredGrade(_requiredGradeToSign);
	checkRequiredGrade(_requiredGradeToExecute);
}

AForm::AForm(const AForm &source) : _name(source._name + "_copy"), _isSigned(source._isSigned), _requiredGradeToSign(source._requiredGradeToSign), _requiredGradeToExecute(source._requiredGradeToExecute)
{
	std::cout << "\e[46mAForm::\e[0m Copy constructor called for " << _name << std::endl;
}

AForm &AForm::operator=(const AForm &source)
{
	if (this != &source)
	{
		_isSigned = source._isSigned;
	}
	
	std::cout << "\e[46mAForm::\e[0m Assignment operator used for " << _name << std::endl;
	  
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "\e[46mAForm::\e[0m Destructor called for " << _name << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

std::string AForm::getName(void) const
{
	return _name;
}

int AForm::getGradeToSign(void) const
{
	return _requiredGradeToSign;
}

int AForm::getGradeToExecute(void) const
{
	return _requiredGradeToExecute;
}

bool AForm::getIsSigned(void) const
{
    return _isSigned;
}


//////////////////////////////////////////////////////////////////////////////////////

const char *AForm::GradeTooHighException::what() const throw()
{
    return "\e[46mAForm::\e[0m \e[4;31mGrade too high!\e[0m";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "\e[46mAForm::\e[0m \e[4;31mGrade too low!\e[0m";
}

const char *AForm::NotSignedException::what() const throw()
{
    return "\e[46mAForm::\e[0m \e[4;31mForm is not signed!\e[0m";
}

//////////////////////////////////////////////////////////////////////////////////////

void AForm::checkRequiredGrade(int grade)
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

void AForm::CanBeExecuted(Bureaucrat const &executor) const
{
    if (getIsSigned() == 0)
        throw NotSignedException();

    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
}

//////////////////////////////////////////////////////////////////////////////////////

void AForm::beSigned(Bureaucrat &b)
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

std::ostream &operator<<(std::ostream &output, AForm const &instance)
{
    output << "AForm: " << instance.getName() << "\nSigned: " << instance.getIsSigned() << "\nRequired Grade to Sign: " << instance.getGradeToSign() << "\nRequired Grade to Execute: " << instance.getGradeToExecute();
   
    return output;
}