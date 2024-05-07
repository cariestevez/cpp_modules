#include "PhoneBook.hpp"

int main()
{
    PhoneBook   phonebook;
	std::string	userInput;

	while (1)
	{
		phonebook.welcomeMessage();
		std::getline(std::cin, userInput);
		//std::cin >> userInput; //reads only until the first whitespace
		if (userInput.compare("ADD") == 0)
			phonebook.addContact();
		else if (userInput.compare("SEARCH") == 0)
		 	phonebook.searchContact();
		else if (userInput.compare("EXIT") == 0)
			break ;
	}
    return (0);
}