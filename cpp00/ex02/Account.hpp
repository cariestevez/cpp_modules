// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	//shared by every instance
	static int	getNbAccounts( void );//returns total num of accounts
	static int	getTotalAmount( void );//returns total amount of money across all accounts
	static int	getNbDeposits( void );//returns total number of deposits made across all accounts
	static int	getNbWithdrawals( void );//returns the total number of withdrawals made across all accounts
	static void	displayAccountsInfos( void );//displays information about the accounts?

	Account( int initial_deposit );//constructor with parameters that initializes an account with an initial deposit
	~Account( void );//destructor for cleaning up resources associated with an account

	void	makeDeposit( int deposit );//Adds a deposit to the account
	bool	makeWithdrawal( int withdrawal );//Makes a withdrawal from the account
	int		checkAmount( void ) const;//Returns the current balance of the account
	void	displayStatus( void ) const;//Displays the status of the account


private:

	//shared by every instance
	static int	_nbAccounts;//total num of accounts
	static int	_totalAmount;//total amount of money across all accounts
	static int	_totalNbDeposits;//total num of deposits across all accounts
	static int	_totalNbWithdrawals;//total num of withdrawals across all accounts
	static void	_displayTimestamp( void );

	//instance specific
	int				_accountIndex;
	int				_amount;//Current balance of the account
	int				_nbDeposits;//Number of deposits made to the account
	int				_nbWithdrawals;//Number of withdrawals made to the account

	Account( void );//default constructor

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
