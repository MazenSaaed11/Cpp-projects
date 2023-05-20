#include"general.h"
map<int, account*> accounts;
map<int, bool> filled;
bool check_account(int password, string phone_number)
{
	if (filled[password] && accounts[password]->get_phone_number() == phone_number)
		return true;
	else
		return false;
}
int account_type()
{
	cout << "\nWhat's the type of the account : \n";
	cout << "1)Savings_account\n";
	cout << "2)checking_account\n";
	cout << "3)trust_account\n";
	int x; cout << "Enter your choise please : "; cin >> x;
	return x;
}   
int returning_to_main_menu()
{
	cout << "Enter 1 to try again or 0 to go back to main menu :";
	int x; cin >> x;
	return x;
}
double amount_to_deposit()
{
	cout << "\nEnter the amount you want to deposit : ";
	double amount; cin >> amount;
	return amount;
}
double amount_to_withdraw()
{
	cout << "\nEnter the amount you want to withdraw : ";
	double amount; cin >> amount;
	return amount;
}
int take_password()
{
	cout << "Enter a password from 5 numbers to 9: ";
	int pass; cin >> pass;
	return pass;
}
void add_account()
{
	int type = account_type();
	int pass = take_password();
	while (filled[pass])
	{
		cout << "Taken password please try again : ";
		cin >> pass;
	}
	filled[pass] = 1;
	if (type == 1)
		accounts[pass] = new savings_account();
	else if (type == 2)
		accounts[pass] = new checking_account();
	else
		accounts[pass] = new trust_account();

	cin >> *accounts[pass];
}
void deposit()
{
again:
	cout << "Enter your phone number : "; string phone_number; cin >> phone_number;
	cout << "Enter your account password : "; int password; cin >> password;
	//normal account

	if (check_account(password, phone_number))
	{
		double amount = amount_to_deposit();
		*accounts[password] += amount;
	}
	else
	{
		cout << "Incorrect information please try again\n";
		int choise = returning_to_main_menu();
		if (choise == 1)
			goto again;
		else
			return;
	}

}
void withdraw() {
again:
	cout << "Enter your phone number : "; string phone_number; cin >> phone_number;
	cout << "Enter your account password : "; int password; cin >> password;
	
	if (check_account(password, phone_number))
	{
		double amount = amount_to_withdraw();
		*accounts[password] -= amount;
	}
	else
	{
		cout << "Incorrect information please try again\n";
		int choise = returning_to_main_menu();
		if (choise == 1)
			goto again;
		else
			return;
	}

}
void display_account() {
again:
	cout << "Enter your phone number : "; string phone_number; cin >> phone_number;
	cout << "Enter your account password : "; int password; cin >> password;

	if (check_account(password, phone_number))
	{
		cout << *accounts[password];
	}
	else
	{
		cout << "Incorrect information please try again\n";
		int choise = returning_to_main_menu();
		if (choise == 1)
			goto again;
		else
			return;
	}
}
void display()
{
	while (true)
	{
		cout << "\n1)Add an account\n";
		cout << "2)Deposit\n";
		cout << "3)Withdraw\n";
		cout << "4)Display my account\n";
		cout << "5)Exit\n";
		int x; cout << "Enter your choise please : "; cin >> x;
		if (x == 1)
			add_account();
		else if (x == 2)
			deposit();
		else if (x == 3)
			withdraw();
		else if (x == 4)
			display_account();
		else if (x == 5)
			exit(0);

	}
}
