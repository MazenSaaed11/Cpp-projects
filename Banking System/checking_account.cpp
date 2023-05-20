#include "checking_account.h"
checking_account::checking_account(double amount, string name, string phone_number)
	:account(amount, name, phone_number) {}
checking_account::checking_account():account(){}


bool checking_account::operator-=(double amount)
{
	balance -= 2; //fees
	return account::operator-=(amount);
}
