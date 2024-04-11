#include "Account.hpp"
#include <iostream>
#include <ctime>

//constructor
//Account( int initial_deposit );

//destructor
//~Account( void );

//getter functions
static int	Account::getNbAccounts(void)
{
   return (_nbAccounts);
}

static int	Account::getTotalAmount(void)
{
    return (_totalAmount);
}

static int	Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

static int	Account::getNbWithdrawals(void)
{
   return (_totalNbWithdrawals);
}

static void	Account::displayAccountsInfos(void);




static void	_displayTimestamp( void )
{
    std::time_t unixTimestamp = 0;
    std::tm *localTimestamp = (nullptr);

    std::time(&unixTimestamp);
    localTimestamp = std::localtime(&unixTimestamp);

    char formattedTimestamp[20];
    std::strftime(formattedTimestamp, sizeof(formattedTimestamp), "[%Y%m%d_%H%M%S]", localTimestamp);

    std::cout << formattedTimestamp << std::endl;
}

static void Account::displayAccountsInfos(void)
{
	std::cout << _displayTimestamp()
    <<"\e[0;35m" << "\n"
              << std::left << std::setw(15) << "Index: " << this->_index << "\n"
              << std::left << std::setw(15) << "First Name: " << this->_firstName << "\n"
              << std::left << std::setw(15) << "Last Name: " << this->_lastName << "\n"
              << std::left << std::setw(15) << "Nickname: " << this->_nickName << "\n"
              << std::left << std::setw(15) << "Phone Number: " << this->_phoneNum << "\n"
              << std::left << std::setw(15) << "Darkest Secret: " << this->_darkestSecret
              << "\033[0m" << std::endl;
}

displayStatus