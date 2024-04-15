#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define MAX_CONTACTS 8

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class	PhoneBook
{
	private:
		Contact	_contacts[MAX_CONTACTS];

	public:
		void 	welcomeMessage(void) const;
		void	addContact(void);
		void	searchContact(void);
};

#endif
