#pragma once
#include"account.h"
class checking_account :public account
{
public:
	checking_account();
    checking_account(double amount, string name, string phone_number);
	bool operator-=(double amount) override;
	bool operator+=(double amount) override { return account::operator+=(amount); }
	void print(ostream& os) const override { account::print(os); }
	void read(istream& os)  override { account::read(os); }
};

