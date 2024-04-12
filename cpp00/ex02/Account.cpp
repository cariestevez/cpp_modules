#include "Account.hpp"
#include <iostream>
#include <ctime>

//default constructor
Account::Account(void)
{
    _accountIndex = 0;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _nbAccounts = 0;
    _totalAmount = 0;
    _totalNbDeposits = 0;
    _totalNbWithdrawals = 0;
}

//constructor
Account::Account(int initial_deposit)//used by the vector constructor in l.24 of tests.cpp
{
    //specific to each instance of the class
    _accountIndex = 0;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    //statics, shared by all instances!!
    _nbAccounts += 1;
    _totalAmount += _amount;

    std::cout   << _displayTimestamp()
                << "index:" << "\e[0;35m" << _accountIndex << "\e[0m" << ';'
                << "amount:" << "\e[0;35m" << _amount << "\e[0m" << ';'
                << "created"
                << std::endl;
}

// destructor
Account::~Account(void)
{
    std::cout   << _displayTimestamp()
            << "index:" << "\e[0;35m" << _accountIndex << "\e[0m" << ';'
            << "amount:" << "\e[0;35m" << _amount << "\e[0m" << ';'
            << "closed"
            << std::endl;
}

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

//functions to implemet
void	Account::makeDeposit( int deposit )
{
    int prevAmount = _amount;
    
    //deposit logic
    
    std::cout   << _displayTimestamp()
            << "index:" << "\e[0;35m" << _accountIndex << "\e[0m" << ';'
            << "p_amount:" << "\e[0;35m" << prevAmount << "\e[0m" << ';'
            << "deposit:" << "\e[0;35m" << deposit << "\e[0m" << ';'
            << "amount:" << "\e[0;35m" << _amount << "\e[0m" << ';'
            << "nb_deposits:" << "\e[0;35m" << _nbDeposits << "\e[0m" << ';'
            << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int prevAmount = _amount;
    
    //withdrawal logic

    std::cout   << _displayTimestamp()
            << "index:" << "\e[0;35m" << _accountIndex << "\e[0m" << ';'
            << "p_amount:" << "\e[0;35m" << prevAmount << "\e[0m" << ';'
            << "withdrawal:" << "\e[0;35m" << withdrawal << "\e[0m" << ';'
            << "amount:" << "\e[0;35m" << _amount << "\e[0m" << ';'
            << "nb_withdrawals:" << "\e[0;35m" << _nbWithdrawals << "\e[0m"
            << std::endl;
}

int		Account::checkAmount( void ) const//Returns the current balance of the account
{

}

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

//printing functions
static void Account::displayAccountsInfos(void)
{
	std::cout   << _displayTimestamp()
                << "accounts:" << "\e[0;35m" << _nbAccounts << "\e[0m" << ';'
                << "total:" << "\e[0;35m" << _totalAmount << "\e[0m" << ';'
                << "deposits:" << "\e[0;35m" << _totalNbDeposits << "\e[0m" << ';'
                << "withdrawals:" << "\e[0;35m" << _totalNbWithdrawals << "\e[0m"
                << std::endl;
}

void    Account::displayStatus( void ) const
{
    std::cout   << _displayTimestamp()
                << "index:" << "\e[0;35m" << _accountIndex << "\e[0m" << ';'
                << "amount:" << "\e[0;35m" << _amount << "\e[0m" << ';'
                << "deposits:" << "\e[0;35m" << _nbDeposits << "\e[0m" << ';'
                << "withdrawals:" << "\e[0;35m" << _nbWithdrawals << "\e[0m"
                << std::endl;
}