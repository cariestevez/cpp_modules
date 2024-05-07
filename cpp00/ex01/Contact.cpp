#include "Contact.hpp"

std::string Contact::getUserInput(std::string message)
{
    std::string userInput;
    int inputCorrect = false;

    while (!inputCorrect)
    {
        std::cout << message << std::endl;
        std::getline(std::cin, userInput);
        if (userInput.find_first_not_of(' ') != std::string::npos)
            inputCorrect = true;
    }
    return (userInput);
}

//setter function
void	Contact::saveContact(int index)
{
    this->_firstName = this->getUserInput("\033[35m--->Enter first name: \033[0m");
    this->_lastName = this->getUserInput("\033[35m--->Enter last name: \033[0m");
    this->_nickName = this->getUserInput("\033[35m--->Enter nickname: \033[0m");
    this->_phoneNum = this->getUserInput("\033[35m--->Enter phone number: \033[0m");
    this->_darkestSecret = this->getUserInput("\033[35m--->Enter darkest secret: \033[0m");
    this->_index = index;
    std::cout << "\033[32mContact saved succesfully! ✅\033[0m" << std::endl;
}

//getter functions
std::string	Contact::getFirstName(void) const
{
    return (this->_firstName);
}

void	Contact::printPreview(void)
{
    this->_firstName = (this->_firstName.length() > 10) ? (this->_firstName.substr(0, 9) + '.') : this->_firstName;
    this->_lastName = (this->_lastName.length() > 10) ? (this->_lastName.substr(0, 9) + '.') : this->_lastName;
    this->_nickName = (this->_nickName.length() > 10) ? (this->_nickName.substr(0, 9) + '.') : this->_nickName;

	std::cout	<< "\033[33m"
				<< std::right << std::setw(10) << this->_index << " | "
				<< std::right << std::setw(10) << this->_firstName << " | "
				<< std::right << std::setw(10) << this->_lastName << " | "
				<< std::right << std::setw(10) << this->_nickName
				<< "\033[0m" << std::endl;
}

void	Contact::printContactFull() const
{	
	if (this->_firstName.empty())
    {
        std::cout << "\033[31mContact not found 👀\033[0m" << std::endl;
        return ;
    }
	std::cout << "\033[33m" << "\n"
              << std::left << std::setw(15) << "Index: " << this->_index << "\n"
              << std::left << std::setw(15) << "First Name: " << this->_firstName << "\n"
              << std::left << std::setw(15) << "Last Name: " << this->_lastName << "\n"
              << std::left << std::setw(15) << "Nickname: " << this->_nickName << "\n"
              << std::left << std::setw(15) << "Phone Number: " << this->_phoneNum << "\n"
              << std::left << std::setw(15) << "Darkest Secret: " << this->_darkestSecret
              << "\033[0m" << std::endl;
}