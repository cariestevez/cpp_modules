#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class	 Contact
{
	private:
		int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNum;
		std::string	_darkestSecret;

	public:
		void		saveContact(int index);
		int			getIndex(void) const;
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickName(void) const;
		std::string	getPhoneNum(void) const;
		std::string	getDarkestSecret(void) const;
		std::string	getUserInput(std::string message);
		void		printPreview(void) const;
		void		printContactFull(void) const;

};

#endif