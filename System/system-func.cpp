#include<iostream>
#include<memory>
#include<fstream>
#include<vector>
#include "../Account/Account.h"
#include "../Bank/Bank.h"

std::unique_ptr<Bank> sbank (new Bank());

void loadFile(std::string filename)
{
	sbank->loadAccountsFromFile(filename);
}

void saveFile(std::string filename)
{
	sbank->saveAccountsToFile(filename);
}

void showMenu()
{
	std::cout << "Select an option:" << std::endl;
	std::cout << "1. Open an account" << std::endl;
	std::cout << "2. Show balance" << std::endl;
	std::cout << "3. Deposit" << std::endl;
	std::cout << "4. Withdrawal" << std::endl;
	std::cout << "5. Close an account" << std::endl;
	std::cout << "6. Close all accounts" << std::endl;
	std::cout << "7. Show all accounts" << std::endl;
	std::cout << "8. Quit" << std::endl;
}

void getUserOption(int option)
{
	switch(option) 
	{
		case 1:
			sbank->openAccount();
			break;
		case 2: 
			break;
		case 3: 
			break;
		case 4:
			break;
		case 5:
			sbank->closeAccount();
			break;
		case 6:
			sbank->closeAllAccounts();
			break;
		case 7:
			sbank->showAccounts();	
			break;
		default:
			std::cout << "Bye" << std::endl;
			break;
	}
}
	
