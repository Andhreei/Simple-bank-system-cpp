#include<iostream>
#include<stdexcept>
#include<memory>
#include<fstream>
#include<vector>
#include "../Account/Account.h"
#include "Bank.h"

/* Opening an account */
void Bank::openAccount()
{
	std::string accOpeningFirstName;
	std::string accOpeningLastName;
	double accOpeningBalance;
	std::cout << "Enter first name: ";
	std::cin >> accOpeningFirstName;
	std::cout << "Enter last name: ";
	std::cin >> accOpeningLastName;
	std::cout << "Enter initial balance: ";
	std::cin >> accOpeningBalance;
	std::shared_ptr<Account> newAccount(new Account(accOpeningFirstName, accOpeningLastName, accOpeningBalance));
	Accounts.push_back(newAccount);
	std::cout << "Account " << newAccount->accountNumber << " created." << std::endl;
}

void Bank::showAccounts()
{
	int i = 1;
	std::cout << "Accounts in the system" << std::endl;
	for(const auto &acc : Accounts)
	{
		std::cout << i++ << ". " << acc->getFirstName() << " " << acc->getLastName() << " " << acc->getBalance() << std::endl;
	}
	std::cout << std::endl;
}

void Bank::saveAccountsToFile(const std::string& filename)
{
	std::ofstream outFile(filename);
	if(!outFile.is_open())
		throw std::runtime_error("Couldn't open file for saving the accounts");
	for(const auto& account : Accounts)
		outFile << *account;
	outFile.close();
}

void Bank::loadAccountsFromFile(const std::string& filename)
{
	std::ifstream inFile(filename);
	if(!inFile.is_open())
		throw std::runtime_error("Couldn't open file for reading the accounts");
	std::string firstName, lastName;
	double balance;
	while(inFile >> firstName >> lastName >> balance)
		Accounts.push_back(std::make_shared<Account>(firstName,lastName,balance));
	inFile.close();
}
