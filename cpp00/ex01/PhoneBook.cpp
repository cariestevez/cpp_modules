#include "PhoneBook.hpp"

void    PhoneBook::welcomeMessage(void) const
{
    std::cout	<< "\033[36m\n"
				<< "Welcome to this crappy awesome ☎️📔! Please enter:\n"
				<< "--->📝 ADD to save a new contact\n"
				<< "--->🔍 SEARCH to display a specific contact info\n"
				<< "--->👋 EXIT to close this phonebook"
				<< "\033[0m" << std::endl; 
}

//creates the instances of Contact
void PhoneBook::addContact(void)
{
    static int  i;

    this->_contacts[i % MAX_CONTACTS].saveContact(i % MAX_CONTACTS);
    i++;
}

void	PhoneBook::searchContact(void)
{
    int i = 0;

    if (this->_contacts[i].getFirstName().empty())
    {
        std::cout << "\033[31mPhoneBook is empty! \033[0m🕳️" << std::endl;
        return ;
    }
    std::cout	<< "\033[33m" << "\n"
				<< std::right << std::setw(10) << "index" << " | "
				<< std::right << std::setw(10) << "first name" << " | "
				<< std::right << std::setw(10) << "last name" << " | "
				<< std::right << std::setw(10) << "nickname"
				<< "\033[0m" << std::endl;
    while (i < 8 && !(this->_contacts[i].getFirstName().empty()))
    {
        this->_contacts[i].printPreview();
        i++;
    }
    std::cout << std::endl;
    std::istringstream iss(this->_contacts[i].getUserInput ("\033[35m--->Enter index of desired contact to view full information: \033[0m"));
    if (!(iss >> i) || !(i >= 0 && i < 8))
    {
        std::cout << "\033[31mError: Invalid input ❗️\033[0m" << std::endl;
        return ;
    }
    this->_contacts[i].printContactFull();
    return ;
}
