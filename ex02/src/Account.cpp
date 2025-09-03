/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:03:10 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/03 13:12:36 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

/*
** Static class-wide counters shared by all Account instances.
** - _nbAccounts: total number of Account objects currently alive.
** - _totalAmount: sum of balances across all accounts.
** - _totalNbDeposits: total number of deposit operations performed.
** - _totalNbWithdrawals: total number of withdrawal operations performed.
*/
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*
** Default constructor.
*/
Account::Account(void)
{

}

/*
** Construct an account with an initial deposit.
** Responsibilities:
** 1) Assign a unique index to this account based on current _nbAccounts.
** 2) Increase the global accounts counter.
** 3) Add the initial deposit to both the instance balance and the
**    global total amount.
** 4) Print a timestamped creation line with index and amount.
**
** Example log:
**   [YYYYMMDD_HHMMSS] index:0;amount:42;created
*/
Account::Account(int initial_deposit ) : _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	/*
	** We are inside the class scope, so referring to _nbAccounts is the
	** same as Account::_nbAccounts. Using 'this->' on instance members
	** improves clarity vs. static class data.
	*/
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount += initial_deposit;
	_totalAmount += this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "amount:" << this->_amount << ";" << "created" << std::endl;
}

/*
** Destructor.
** Responsibilities:
** 1) Decrease the global accounts counter to reflect account closure.
** 2) Print a timestamped closure line with the last known amount.
**
** Example log:
**   [YYYYMMDD_HHMMSS] index:0;amount:37;closed
*/
Account::~Account(void)
{
	Account::_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";" << "closed" << std::endl;
}

/*
** Perform a deposit into this account.
** Parameters:
**   - deposit: positive integer amount to add.
**
** Behavior:
** 1) Log the operation with previous amount (p_amount), the deposit,
**    the resulting amount, and the new per-account deposit count.
** 2) Update both this account's balance and the global total amount.
** 3) Increment deposit counters (per-account and global).
**
** Example log:
**   [YYYYMMDD_HHMMSS] index:0;p_amount:37;deposit:5;amount:42;nb_deposits:1
*/
void	Account::makeDeposit(int deposit)
{
	int	p_amount;

	p_amount = this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << p_amount
			<< ";" << "deposit:" << deposit << ";" << "amount:" << p_amount + deposit
			<< ";" << "nb_deposits:" << this->_nbDeposits + 1 << std::endl;
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits += 1;
	_totalNbDeposits +=  1;
}

/*
** Attempt to withdraw funds from this account.
** Parameters:
**   - withdrawal: positive integer amount to subtract.
**
** Behavior:
** 1) If the withdrawal would cause a negative balance, refuse it:
**      - Print timestamped line with "withdrawal:refused".
**      - Return false and leave all counters unchanged.
** 2) Otherwise:
**      - Subtract from this account and the global total.
**      - Increment withdrawal counters (per-account and global).
**      - Print a detailed timestamped line of the operation.
**      - Return true.
**
** Example success log:
**   [YYYYMMDD_HHMMSS] index:0;p_amount:42;withdrawal:5;amount:37;nb_withdrawals:1
**
** Example refusal log:
**   [YYYYMMDD_HHMMSS] index:0;p_amount:3;withdrawal:refused
*/
bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;

	if ((this->_amount - withdrawal) < 0)
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";" << "p_amount:"
			<< this->_amount << ";" << "withdrawal:" << "refused" << '\n';
		return (false);
	}
	p_amount = this->_amount;
	_displayTimestamp();
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	std::cout << "index:" << this->_accountIndex << ";" << "p_amount:"
			<< p_amount << ";" << "withdrawal:" << withdrawal << ";"
			<< "amount:" << this->_amount << ";"
			<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

/*
** Print a one-line status snapshot for this account.
** The line includes index, current amount, number of deposits,
** and number of withdrawals. A timestamp prefix is included.
**
** Example:
**   [YYYYMMDD_HHMMSS] index:0;amount:37;deposits:1;withdrawals:1
*/
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:"
				<< this->_amount << ";" << "deposits:" << this->_nbDeposits << ";"
				<< "withdrawals:" << this->_nbWithdrawals << "\n";
}

/*
** Print a one-line aggregated snapshot across all accounts.
** The line includes:
**   - accounts: number of accounts alive
**   - total: sum of all balances
**   - deposits: total deposits performed
**   - withdrawals: total withdrawals performed
** A timestamp prefix is included.
**
** Example:
**   [YYYYMMDD_HHMMSS] accounts:3;total:121;deposits:5;withdrawals:2
*/
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";" << "total:"
			<< getTotalAmount() << ";" << "deposits:" << getNbDeposits()
			<< ";" << "withdrawals:" << getNbWithdrawals() << std::endl;
}

/*
** Print a timestamp prefix in the format "[YYYYMMDD_HHMMSS] ".
** This helper is used by all logging methods to keep a consistent
** time format across the output.
**
** Notes:
** - Uses std::time / std::localtime to fetch the current local time.
** - std::strftime writes into a fixed-size buffer.
*/
void	Account::_displayTimestamp(void)
{
	char		timestamp[20];
	std::time_t	now;

	std::time(&now);
	std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", std::localtime(&now));
	std::cout << "[" << timestamp << "] ";
}


/*
** Return the current balance of this account.
** This does not print anything; it is a simple accessor.
*/
int	Account::checkAmount(void) const
{
	return (this->_amount);
}

/*
** Return the total number of accounts currently alive.
** Static accessor for class-wide state.
*/
int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

/*
** Return the sum of balances across all accounts.
** Static accessor for class-wide state.
*/
int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

/*
** Return the total number of deposit operations performed
** across all accounts since program start.
*/
int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

/*
** Return the total number of withdrawal operations performed
** across all accounts since program start.
*/
int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
