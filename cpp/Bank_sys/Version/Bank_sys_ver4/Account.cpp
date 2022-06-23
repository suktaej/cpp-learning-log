#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int id,int money,char* name):AccID(id),Balance(money)
{
	Customer_Name=new char[strlen(name)+1];
	strcpy(Customer_Name,name);
}

Account::Account(const Account& ref):AccID(ref.AccID),Balance(ref.Balance)
{
	Customer_Name=new char[strlen(ref.Customer_Name)+1];
	strcpy(Customer_Name,ref.Customer_Name);
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

Account::~Account()
{
	if(Customer_Name!=NULL)
		delete[] Customer_Name;
}
