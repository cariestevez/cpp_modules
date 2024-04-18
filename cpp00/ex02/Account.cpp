#include "Account.hpp"
#include <iostream>
#include <ctime>

//statics declaration
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//default constructor
Account::Account(void)
{
    _accountIndex = 0;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
}

//constructor
Account::Account(int initial_deposit)//used by the vector constructor in l.24 of tests.cpp
{
    //statics, shared by all instances!!
    _nbAccounts += 1;

    //specific to each instance of the class
    _accountIndex = _nbAccounts - 1;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    //statics, shared by all instances!!
    _totalAmount += _amount;

    _displayTimestamp();
    std::cout   << "index:"     << "\e[0;35m" << _accountIndex  << "\e[0m" << ';'
                << "amount:"    << "\e[0;35m" << _amount        << "\e[0m" << ';'
                << "created"
                << std::endl;
}

// destructor
Account::~Account(void)
{
    _displayTimestamp();
    std::cout   << "index:"     << "\e[0;35m" << _accountIndex  << "\e[0m" << ';'
                << "amount:"    << "\e[0;35m" << _amount        << "\e[0m" << ';'
                << "closed"
                << std::endl;
}

//getter functions
int	Account::getNbAccounts(void)
{
   return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
   return (_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const//Returns the current balance of the account
{
    return (_amount);
}

//functions to implemet
void	Account::makeDeposit( int deposit )
{
    int prevAmount = _amount;
    
    //deposit logic
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout   << "index:"         << "\e[0;35m" << _accountIndex  << "\e[0m" << ';'
                << "p_amount:"      << "\e[0;35m" << prevAmount     << "\e[0m" << ';'
                << "deposit:"       << "\e[0;35m" << deposit        << "\e[0m" << ';'
                << "amount:"        << "\e[0;35m" << _amount        << "\e[0m" << ';'
                << "nb_deposits:"   << "\e[0;35m" << _nbDeposits    << "\e[0m" << ';'
                << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int prevAmount = _amount;
    
    //withdrawal logic
    _displayTimestamp();
    std::cout   << "index:"             << "\e[0;35m" << _accountIndex  << "\e[0m" << ';'
                << "p_amount:"          << "\e[0;35m" << prevAmount     << "\e[0m" << ';';
    
    if (withdrawal > _amount)
    {
        std::cout   << "withdrawal:"    << "refused"
                    << std::endl;
        return (false);
    }

    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout   << "withdrawal:"        << "\e[0;35m" << withdrawal     << "\e[0m" << ';'
                << "amount:"            << "\e[0;35m" << _amount        << "\e[0m" << ';'
                << "nb_withdrawals:"    << "\e[0;35m" << _nbWithdrawals << "\e[0m"
                << std::endl;
    return (true);
}

void	Account::_displayTimestamp( void )
{
    std::time_t unixTimestamp = 0;
    std::tm *localTimestamp = (NULL);

    std::time(&unixTimestamp);
    localTimestamp = std::localtime(&unixTimestamp);

    char formattedTimestamp[20];
    std::strftime(formattedTimestamp, sizeof(formattedTimestamp), "[%Y%m%d_%H%M%S]", localTimestamp);

    std::cout << formattedTimestamp << ' ';
}

//printing functions
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
	std::cout   << "accounts:"      << "\e[0;35m" << _nbAccounts            << "\e[0m" << ';'
                << "total:"         << "\e[0;35m" << _totalAmount           << "\e[0m" << ';'
                << "deposits:"      << "\e[0;35m" << _totalNbDeposits       << "\e[0m" << ';'
                << "withdrawals:"   << "\e[0;35m" << _totalNbWithdrawals    << "\e[0m"
                << std::endl;
}

void    Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout   << "index:"         << "\e[0;35m" << _accountIndex  << "\e[0m" << ';'
                << "amount:"        << "\e[0;35m" << _amount        << "\e[0m" << ';'
                << "deposits:"      << "\e[0;35m" << _nbDeposits    << "\e[0m" << ';'
                << "withdrawals:"   << "\e[0;35m" << _nbWithdrawals << "\e[0m"
                << std::endl;
}
