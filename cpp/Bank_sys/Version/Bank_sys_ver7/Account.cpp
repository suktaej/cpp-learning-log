#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int id,int money,std::string name):AccID(id),Balance(money)
{
	Customer_Name=name;
}

void Account::Deposit(int money){Balance+=money;}

int Account::Withdraw(int money)
{
	if(Balance<money)
		return 0;

	Balance-=money;
	return money;
}

void Account::ShowInfo(void) const
{
	std::cout<<"------------------------"<<std::endl;
	std::cout<<"ID:\t\t"<<AccID<<std::endl;
	std::cout<<"Name:\t\t"<<Customer_Name<<std::endl;
	std::cout<<"Balance:\t"<<Balance<<std::endl;
	std::cout<<"------------------------"<<std::endl;
}
