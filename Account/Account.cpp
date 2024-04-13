#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<iomanip>
#include "Account.h"
#include "../Bank/Bank.h"


int Account::accountsCounting = 1;

/* Constructor */
Account::Account(std::string firstName, std::string lastName, double balance = 0)
{
	this->setFirstName(firstName);
	this->setLastName(lastName);
	this->setBalance(balance);
	this->accountNumber = accountsCounting++;
}

/* Sets the first name */
void Account::setFirstName(std::string fname)
{
	this->firstName = fname;
}

/* Sets the last name */
void Account::setLastName(std::string lname)
{
	this->lastName = lname;
}

/* Sets the balance */
void Account::setBalance(double bkBalance)
{
	this->balance = bkBalance;
}

/* Gets the Account Number */
int Account::getAccountNumber()
{
	return this->accountNumber;
}

/* Gets the Balance */
double Account::getBalance()
{
	return this->balance;
}

/* Gets the first name */
std::string Account::getFirstName()
{
	return this->firstName;
}

/* Gets the last name */
std::string Account::getLastName()
{
	return this->lastName;
}

std::ostream& operator<<(std::ostream& out,const Account& account)
{
	out << account.firstName << std::endl;
	out << account.lastName << std::endl;
	out << account.balance << std::endl;
	return out;
}

