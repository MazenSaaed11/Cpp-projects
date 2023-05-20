#include "trust_account.h"
trust_account::trust_account() :number_of_withdraws{ 0 },savings_account() {}
trust_account::trust_account(int int_ratee, double amount, string namee,
	string phone_numberr) : number_of_withdraws{ 0 },savings_account(int_ratee, amount, namee, phone_numberr) {}
bool trust_account::operator+=(double amount)
{
	if (amount >= 5000)
		balance += 50;

	return savings_account::operator+=(amount);
}
bool trust_account::operator-=(double amount)
{
	
	if (balance / amount < 5.0)
	{
		cout << "Can't withdraw this amount sorry\n";
		cout << "Maximum amount to withdraw is :" << balance / 5.0 << endl;
		cout << "Do you want to make a new withdraw ??( 1 for yes , 0 for no )\n";
		int choise; cin >> choise;
		if (choise == 0)
			return false;
		else
		{
			cout << "Enter the amount you want to withdraw please : ";
			int amount; cin >> amount;
			return trust_account::operator-=(amount);
		}
	}
	else
	{
		number_of_withdraws++;
		return savings_account::operator-=(amount);
	}
}
int trust_account::get_number_of_withdraws()
{
	return number_of_withdraws;
}
void trust_account::print(ostream& os) const {
	os << "Number of withdrawels is : " << number_of_withdraws;
	account::print(os);
}
void trust_account::read(istream& os)   { 
	account::read(os);
}