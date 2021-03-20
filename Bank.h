#pragma once
#include "Client.h"
#include "Account.h"
#include <string>

using namespace std;

class Bank
{
public:
	Bank(int c, int a);
	~Bank();

	Client *GetClient(int c);
	Account *GetAccount(int n);

	Client *CreateClient(int c, string n);
	Account *CreateAccount(int n, Client *c);
	Account *CreateAccount(int n, Client *c, double ir);
	Account *CreateAccount(int n, Client *c, Client *p);
	Account *CreateAccount(int n, Client *c, Client *p, double ir);

	void AddInterest();

private:
	Client **clients;
	int clientsCount;

	Account **accounts;
	int accountsCount;
};

