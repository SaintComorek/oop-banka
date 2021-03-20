#include <iostream>
#include "Client.h"
#include "Account.h"
#include "Bank.h"

using namespace std;

void PrintBank(Bank *b);

int main()
{
	Bank *banka = new Bank(10, 10);

	banka->CreateClient(1,   "Tricia McMillanova");
	banka->CreateClient(2,   "Robot Marvin");
	banka->CreateClient(3,   "Slartibartfast");
	banka->CreateClient(42,  "Arthur Dent");
	banka->CreateClient(420, "Ford Prefect");
	banka->CreateClient(666, "Zafod Biblbrox");

	banka->CreateAccount(4674, banka->GetClient(1), banka->GetClient(2));
	banka->CreateAccount(9273, banka->GetClient(2), 1.5);
	banka->CreateAccount(3409, banka->GetClient(3), banka->GetClient(42));
	banka->CreateAccount(8139, banka->GetClient(42), banka->GetClient(420), 1.2);
	banka->CreateAccount(7061, banka->GetClient(420), banka->GetClient(42), 1.2);
	banka->CreateAccount(1234, banka->GetClient(666));

	banka->GetAccount(4674)->Deposit(500);
	banka->GetAccount(9273)->Deposit(5000);
	banka->GetAccount(3409)->Deposit(10000);
	banka->GetAccount(8139)->Deposit(50);
	banka->GetAccount(7061)->Deposit(100);
	banka->GetAccount(1234)->Deposit(666666);

	PrintBank(banka);

	cout << "*************************************************" << endl;

	banka->GetAccount(4674)->WithDraw(500);
	banka->GetAccount(9273)->WithDraw(500);
	banka->GetAccount(3409)->WithDraw(500);
	banka->GetAccount(8139)->WithDraw(500);
	banka->GetAccount(7061)->WithDraw(500);
	banka->GetAccount(1234)->WithDraw(500);

	banka->AddInterest();

	PrintBank(banka);

	system("pause");
	return 0;
}

void PrintBank(Bank *b)
{
	int pole[] = { 4674,9273,3409,8139,7061,1234 };

	for (int i = 0; i < 6; i++)
	{
		cout << "Meno: " << b->GetAccount(pole[i])->GetOwner()->GetName() << endl;
		cout << "Zostatok: " << b->GetAccount(pole[i])->GetBalance() << " korun" << endl;

		if (b->GetAccount(pole[i])->GetInterestRate() != 1)
			cout << "Urok: " << (b->GetAccount(pole[i])->GetInterestRate() - 1) * 100 << "%" << endl;

		if (b->GetAccount(pole[i])->GetPartner() != nullptr)
			cout << "Partner: " << b->GetAccount(pole[i])->GetPartner()->GetName() << endl;
		cout << endl;
	}

}