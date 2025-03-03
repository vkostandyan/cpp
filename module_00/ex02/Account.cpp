#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() {}

Account::~Account() 
{
    _displayTimestamp();
	std::cout << " index:" << this->_accountIndex  << ";" << "amount:" 
                << this->_amount  << ";closed" << std::endl;

}

Account::Account(int initial_deposit) 
{
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbAccounts++;
    _displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";created" << std::endl;
}

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

void Account::_displayTimestamp(void    )
{
    std::time_t t = std::time(0);
    std::tm* timeInfo = std::localtime(&t);
    std::cout << "[" << (1900 + timeInfo->tm_year)
              << std::setw(2) << std::setfill('0') << (1 + timeInfo->tm_mon)
              << std::setw(2) << std::setfill('0') << timeInfo->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << timeInfo->tm_hour
              << std::setw(2) << std::setfill('0') << timeInfo->tm_min
              << std::setw(2) << std::setfill('0') << timeInfo->tm_sec;
			  std::cout << "]";
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
			<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int p_amount = this->_amount;
	_totalNbDeposits++;
	this->_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << p_amount
			<< ";deposit:" << deposit << ";amount:" << this->_amount
			<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount = this->_amount;
	if(this->_amount - withdrawal < 0)
	{
		_displayTimestamp();
		std::cout << " index:" << this->_accountIndex << ";p_amount:" << p_amount
			<< ";withdrawal:refused" << std::endl;
		return(false);
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << p_amount
			<< ";withdrawal:" << withdrawal << ";amount:" << this->_amount
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return(true);
}

int		Account::checkAmount( void ) const
{
	return(1);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()  << ";total:" << getTotalAmount()  << ";deposits:"
			<< getNbDeposits() << ";withdrawals:" <<  getNbWithdrawals() << std::endl;
}
