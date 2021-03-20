#include "Account.h"

Account::Account(int n, Client *c)
{
	this->number = n;
	this->owner = c;
	this->interestRate = 1;
	this->partner = nullptr;
	this->balance = 0;
}

Account::Account(int n, Client *c, double ir)
{
	this->number = n;
	this->owner = c;
	this->interestRate = ir;
	this->partner = nullptr;
	this->balance = 0;
}

Account::Account(int n, Client *c, Client *p)
{
	this->number = n;
	this->owner = c;
	this->interestRate = 1;
	this->partner = p;
	this->balance = 0;
}

Account::Account(int n, Client *c, Client *p, double ir)
{
	this->number = n;
	this->owner = c;
	this->interestRate = ir;
	this->partner = p;
	this->balance = 0;
}

int Account::GetNumber()
{
	return this->number;
}

double Account::GetBalance()
{
	return this->balance;
}

double Account::GetInterestRate()
{
	return this->interestRate;
}

Client * Account::GetOwner()
{
	return this->owner;
}

Client * Account::GetPartner()
{
	return this->partner;
}

bool Account::CanWithDraw(double a)
{
	if (this->balance >= a)
	{
		return true;
	}

	return false;
}

void Account::Deposit(double a)
{
	this->balance += a;
}

bool Account::WithDraw(double a)
{
	if (this->CanWithDraw(a))
	{
		this->balance -= a;
		return true;
	}

	return false;
}

void Account::AddInterest()
{
	this->balance *= this->interestRate;
}
