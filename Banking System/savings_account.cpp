#include "savings_account.h"

savings_account::savings_account(int int_ratee, double amount, string namee,
	string phone_numberr):int_rate{int_ratee},account(amount,namee,phone_numberr){}
savings_account::savings_account():int_rate{10},account(){}


bool savings_account::operator+=(double amount) 
{
	amount = amount + amount * (int_rate / 100.0);
	return account::operator+=(amount);
}

void savings_account::print(ostream& os) const {
	account::print(os);
	os << "\n and int_rate is : " << int_rate << '\n';
}

void savings_account::read(istream& os)
{
	cout << "\nEnter the int_rate please : ";
	cin >> int_rate;
	account::read(os);
}
