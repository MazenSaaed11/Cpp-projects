#pragma once
#include"savings_account.h"
class trust_account:public savings_account
{
    int number_of_withdraws;
public:
	trust_account();
	trust_account(int int_ratee, double amount, string namee, string phone_numberr);
	bool operator+=(double amount) override;
	bool operator-=(double amount) override;
	void print(ostream& os) const override;
	void read(istream& os)  override;
	int get_number_of_withdraws();

};

