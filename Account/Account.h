class Bank;

class Account
{
	public:
		Account(std::string firstName, std::string lastName, double balance);
		void setFirstName(std::string fname);
		void setLastName(std::string lname);
		void setBalance(double bkBalance);
		int getAccountNumber();
		double getBalance();
		std::string getFirstName();
		std::string getLastName();
		static int accountsCounting;
		friend class Bank;
		friend std::ostream& operator<<(std::ostream& out,const Account& account);

	private:
		int accountNumber;
		double balance;
		std::string firstName;
		std::string lastName;
};
