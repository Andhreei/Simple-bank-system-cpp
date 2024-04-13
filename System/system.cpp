#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>
#include <iomanip>
#include <fstream>
#include "system-func.h"
#include "../Account/Account.h"
#include "../Bank/Bank.h"

int main()
{
	std::cout << std::fixed << std::setprecision(2);	
	try
	{
	loadFile("Accounts.txt");
	int choice = 0;
	while(choice != 8)
	{
		showMenu();
		std::cout << "Enter your option: ";
		std::cin >> choice;
		getUserOption(choice);
	}
	saveFile("Accounts.txt");
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
