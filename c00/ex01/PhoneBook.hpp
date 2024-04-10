#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define MAX_CONTACTS 8

#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	_contacts[MAX_CONTACTS];
	public:
		void	addContact(void);
		void	searchContact(void)	const;
		void	printContact(void) const;
		void 	welcomeMessage(void) const;	
};

#endif
