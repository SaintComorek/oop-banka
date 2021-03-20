#pragma once
#include "Client.h"
#include <string>

using namespace std;

class Account
{
public:
	Account(int n, Client *c);
	Account(int n, Client *c, double ir);
	Account(int n, Client *c, Client *p);
	Account(int n, Client *c, Client *p, double ir);

	int GetNumber();
	double GetBalance();
	double GetInterestRate();
	Client *GetOwner();
	Client *GetPartner();
	bool CanWithDraw(double a);

	void Deposit(double a);
	bool WithDraw(double a);
	void AddInterest();

private:
	int number;
	double balance;
	double interestRate;

	Client *owner;
	Client *partner;
};

