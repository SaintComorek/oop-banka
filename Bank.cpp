#include "Bank.h"

Bank::Bank(int c, int a)
{
	this->clients = new Client*[c];
	this->clientsCount = 0;
	this->accounts = new Account*[a];
	this->accountsCount = 0;
}

Bank::~Bank()
{
	delete[] this->accounts;
	delete[] this->clients;
}

Client *Bank::GetClient(int c)
{
	for (int i = 0; i < this->clientsCount; i++)
	{
		if (clients[i]->GetCode() == c)
		{
			return clients[i];
		}
	}

	return nullptr;
}

Account *Bank::GetAccount(int n)
{
	for (int i = 0; i < this->accountsCount; i++)
	{
		if (accounts[i]->GetNumber() == n)
		{
			return accounts[i];
		}
	}

	return nullptr;
}

Client *Bank::CreateClient(int c, string n)
{
	Client *temp = new Client(c, n);

	this->clients[this->clientsCount++] = temp;
	return temp;
}

Account *Bank::CreateAccount(int n, Client *c)
{
	Account *temp = new Account(n, c);

	this->accounts[this->accountsCount++] = temp;
	return temp;
}

Account *Bank::CreateAccount(int n, Client *c, double ir)
{
	Account *temp = new Account(n, c, ir);

	this->accounts[this->accountsCount++] = temp;
	return temp;
}

Account *Bank::CreateAccount(int n, Client *c, Client *p)
{
	Account *temp = new Account(n, c, p);

	this->accounts[this->accountsCount++] = temp;
	return temp;
}

Account *Bank::CreateAccount(int n, Client *c, Client *p, double ir)
{
	Account *temp = new Account(n, c, p, ir);

	this->accounts[this->accountsCount++] = temp;
	return temp;
}

void Bank::AddInterest()
{
	for (int i = 0; i < this->accountsCount; i++)
	{
		this->accounts[i]->AddInterest();
	}
}
