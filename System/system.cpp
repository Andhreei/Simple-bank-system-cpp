#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>
#include <fstream>
#include "system-func.h"
#include "../Account/Account.h"
#include "../Bank/Bank.h"

int main()
{
	try
	{
	loadFile("Accounts.txt");
	int choice = 0;
	while(choice != 7)
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
