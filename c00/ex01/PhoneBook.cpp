#include "PhoneBook.hpp"

void    PhoneBook::welcomeMessage(void) const
{
    std::cout << "\033[34mWelcome to my awesome phonebook!\n\
- Enter ADD to save a new contact\n\
- Enter SEARCH to display a specific contact info\n\
- or enter EXIT to close this phonebook\033[0m" << std::endl; 
}

void PhoneBook::addContact(void)
{
    static int  i;

    this->_contacts[i % MAX_CONTACTS].saveContact(i % MAX_CONTACTS);
    i++;
}

// void	PhoneBook::searchContact(void)	const
// {

// }

// void	PhoneBook::printContact(void) const
// {

// }
