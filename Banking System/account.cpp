#include "account.h"


ostream& operator<<(ostream& out, const printable& p) {
	p.print(out);
	return out;
}

istream& operator>>(istream& in, readable& p)
{
	p.read(in);
	return in;
}




account::account()
{

}

account::account(int amount, string namee, string phone_numberr)
{
	balance = amount;
	name = namee;
	phone_number = phone_numberr;
}

bool account::operator+=(double amount)
{
	balance += amount;
	cout << "your current balance is : " << balance << endl;
	return true;
}
bool account::operator-=(double amount)
{
	if (amount > balance)
	{
		cout << "Insuffecient funds\n";
		cout << "Your balance is : " << balance << endl;
		cout << "Do you want to make another withdrawal??(1=yes,0=no) : ";
	    int x; cin >> x;
		if (x == 1)
		{
			cout << "Enter the amount you want to withdraw : ";
			double amount; cin >> amount;
			account::operator-=(amount);
		}
		else
		return false;
	}
	else
	{
		cout << "Succesful withdral\n";
		balance -= amount;
		cout << "Your current balance is : " << balance;
		return true;
	}
}
void account::print(ostream& out) const
{
	out << "\nYour name is : " << name << '\n';
	out << "\nYour phone number is : " << phone_number << '\n';
	out << "\nYour balance is : " << balance << '\n';
}
void account::read(istream& in)
{
	cout << "\nEnter Your name please : ";
	in >> name;
	cout << "\nEnter your Phone number please : ";
	in >> phone_number;
	cout << "\nEnter the first balance please : ";
	in >> balance;
}
string account ::get_phone_number()
{
	return phone_number;
}
