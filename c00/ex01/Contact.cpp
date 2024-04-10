#include "Contact.hpp"

int	Contact::getIndex(void) const
{
	return (this->_index);
}

std::string Contact::_getUserInput(std::string message)
{
    std::string userInput;
    int inputCorrect = false;

    while (!inputCorrect)
    {
        std::cout << message << std::endl;
        std::cin >> userInput;
        if (!userInput.empty())
            inputCorrect = true;
        // else
        //     std::cin.clear();
    }
    return (userInput);
}

void	Contact::saveContact(int index)
{
    this->_firstName = this->_getUserInput("\033[35mEnter first name: \033[0m");
    this->_lastName = this->_getUserInput("\033[35mEnter last name: \033[0m");
    this->_nickName = this->_getUserInput("\033[35mEnter nickname: \033[0m");
    this->_phoneNum = this->_getUserInput("\033[35mEnter phone number: \033[0m");
    this->_darkestSecret = this->_getUserInput("\033[35mEnter darkest secret: \033[0m");
    this->_index = index;
    std::cout << "🤓\033[32m Contact saved succesfully! 🤓\033[0m" << std::endl;
}
