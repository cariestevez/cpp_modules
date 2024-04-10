#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define MAX_CONTACTS 8

#include "Contact.hpp"

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
