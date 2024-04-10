#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>

class	 Contact
{
	private:
		int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNum;
		std::string	_darkestSecret;

		std::string	_getUserInput(std::string message);
	
	public:
		int		getIndex(void) const;
		void	saveContact(int index);
};

#endif