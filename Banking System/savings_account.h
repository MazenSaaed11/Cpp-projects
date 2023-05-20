#pragma once
#include"checking_account.h"
class savings_account:public account
{
protected:
	int int_rate;
public:
	savings_account();
	savings_account(int int_rate,double amount, string namee, string phone_numberr);
	bool operator+=(double amount) override;
	bool operator-=(double amount) override { return account::operator-=(amount);}
	void print(ostream& os) const override;
	void read(istream& os)  override;
};

