#pragma once
#include<iostream>
#include<string>
using namespace std;
class printable {
	friend ostream& operator << (ostream& out, const printable& p);

public:
	virtual void print(ostream& out) const = 0;
	virtual ~printable() {}
};

class readable {
	friend istream& operator >> (istream& out, readable& p);

public:
	virtual void read(istream& out) = 0;
	virtual ~readable() {}
};

class account : public printable,public readable
{
protected:
	double balance;
	string name;
	string phone_number;
public:

	account();
	account(int amount, string namee, string phone_numberr);
	virtual bool operator+=(double amount) = 0;  // deposit
	virtual bool operator-=(double amount) = 0; // withdraw
	virtual void print(ostream& out)const override = 0;
	virtual void read(istream& out)override = 0;
	string get_phone_number();
	virtual ~account() = default;
};

