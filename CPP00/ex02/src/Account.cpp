/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:02:12 by sbalk             #+#    #+#             */
/*   Updated: 2024/02/08 14:10:46 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <chrono>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/********************************************************************/
/*                          DEFAULT CONSTRUCTOR                     */
/********************************************************************/

Account::Account(void) {
	_accountIndex = 0;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

/********************************************************************/
/*                         PARAMETERISZED CONSTRUCTOR               */
/********************************************************************/

Account::Account(int initial_deposit) :
		_accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

Account::~Account(void) {
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

/********************************************************************/
/*                          PUBLIC                                  */
/********************************************************************/

int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}
int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}
int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}
void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}
bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount(void) const {
	_totalNbWithdrawals++;
	return _amount;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

/********************************************************************/
/*                          PRIVATE                                 */
/********************************************************************/

void Account::_displayTimestamp(void) {
	time_t now = time(NULL);
	struct tm *now_tm = localtime(&now);
	std::cout << std::setfill('0')
			  << "[" << (now_tm->tm_year + 1900)
			  << std::setw(2) << now_tm->tm_mon + 1
			  << std::setw(2) << now_tm->tm_mday << "_"
			  << std::setw(2) << now_tm->tm_hour
			  << std::setw(2) << now_tm->tm_min
			  << std::setw(2) << now_tm->tm_sec << "] ";
}
