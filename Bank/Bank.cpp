#include<iostream>
#include<stdexcept>
#include<memory>
#include<fstream>
#include<vector>
#include<iomanip>
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

/* Closing an account */
void Bank::closeAccount()
{
	if(Accounts.empty())
	{
		std::cout << "The system does not contain any account, nothing to be deleted" << std::endl;
	}
	else
	{
		uint64_t index = 0;
		std::cout << "Which account you want to close? (Enter the number): ";
		std::cin >> index;
		if(index < 1 || index > Accounts.size())
		{
			std::cout << "The number of account you want to delete is not in range of existing ones" << std::endl;
		}
		else
		{
			index--;
			std::cout << "Account " << Accounts[index]->getFirstName() << " " << Accounts[index]->getLastName() << " deleted" << std::endl;
			Accounts.erase(Accounts.begin() + index);
		}
	}
}

/* Closing all Accounts */
void Bank::closeAllAccounts()
{
	Accounts.clear();
	std::cout << "All accounts were deleted" << std::endl;
}

/* Showing the accounts */
void Bank::showAccounts()
{
	if(Accounts.empty())
	{
		std::cout << "The system does not have any accounts in it" << std::endl;
	}
	else
	{
		int i = 1;
		std::cout << "Accounts in the system" << std::endl;
		for(const auto &acc : Accounts)
		{
			std::cout << i++ << ". " << acc->getFirstName() << " " << acc->getLastName() << " " << acc->getBalance() << std::endl;
		}
		std::cout << std::endl;
	}
}

/* Saving the accounts to memory */
void Bank::saveAccountsToFile(const std::string& filename)
{
	std::ofstream outFile(filename);
	outFile << std::fixed << std::setprecision(2);
	if(!outFile.is_open())
		throw std::runtime_error("Couldn't open file for saving the accounts");
	for(const auto& account : Accounts)
		outFile << *account;
	outFile.close();
}

/* Loading the accounts from memory */
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

/* Depositing an amount */
void Bank::deposit()
{
	if(Accounts.empty())
	{
		std::cout << "The system does not contain any account, nowhere to deposit in" << std::endl;
	}
	else
	{
		uint64_t index = 0;
		std::cout << "Which account you want to deposit in? (Enter the number): ";
		std::cin >> index;
		if(index < 1 || index > Accounts.size())
		{
			std::cout << "The number of account you want to deposit in is not in range of existing ones" << std::endl;
		}
		else
		{
			double depositAmount = 0;
			std::cout << "What amount you want to deposit?: ";
			std::cin >> depositAmount;
			if(depositAmount < 1)
			{
				std::cout << "You can not deposit negative values or nothing" << std::endl;
			}
			else
			{
				index--;
				double oldBalance = Accounts[index]->getBalance();
				double newBalance = oldBalance + depositAmount;
				Accounts[index]->setBalance(newBalance);
				std::cout << "Succes, new balance is: " << Accounts[index]->getBalance() << std::endl;
			}
		}
	}
}

/* Withdrawing an amount */
void Bank::withdraw()
{
	if(Accounts.empty())
	{
		std::cout << "The system does not contain any account, nowhere to withdraw from" << std::endl;
	}
	else
	{
		uint64_t index = 0;
		std::cout << "Which account you want to withdraw from? (Enter the number): ";
		std::cin >> index;
		if(index < 1 || index > Accounts.size())
		{
			std::cout << "The number of account you want to withdraw from is not in range of existing ones" << std::endl;
		}
		else
		{
			index--;
			double withdrawAmount = 0;
			std::cout << "What amount you want to withdraw?: ";
			std::cin >> withdrawAmount;
			if(withdrawAmount < 1)
			{
				std::cout << "You can not withdraw negative values or nothing" << std::endl;
			}
			else if(withdrawAmount > Accounts[index]->getBalance())
			{
				std::cout << "Insufficient funds" << std::endl;
			}
			else
			{	
				double oldBalance = Accounts[index]->getBalance();
				double newBalance = oldBalance - withdrawAmount;
				Accounts[index]->setBalance(newBalance);
				std::cout << "Succes, new balance is: " << Accounts[index]->getBalance() << std::endl;
			}
		}
	}
}

/* Enquiere an account */
void Bank::enqBalance()
{
	if(Accounts.empty())
	{
		std::cout << "The system does not contain any account" << std::endl;
	}
	else
	{
		uint64_t index = 0;
		std::cout << "Which account you want to enquiere? (Enter the number): ";
		std::cin >> index;
		if(index < 1 || index > Accounts.size())
		{
			std::cout << "The number of account you want to enquiere is not in range of existing ones" << std::endl;
		}
		else
		{
			index--;
			std::cout << "The balance for: " << Accounts[index]->getFirstName() << " " << Accounts[index]->getLastName() << " is " << Accounts[index]->getBalance() << std::endl;
		}
	}
}
