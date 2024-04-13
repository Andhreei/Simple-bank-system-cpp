#include<memory>

class Bank
{
	public:
		void openAccount();
		void closeAccount();
		void closeAllAccounts();
		void deposit();
		void withdraw();
		void enqBalance();
		void showAccounts();
		void saveAccountsToFile(const std::string& filename);
		void loadAccountsFromFile(const std::string& filename);
	private:
		std::vector<std::shared_ptr<Account>> Accounts;
};
