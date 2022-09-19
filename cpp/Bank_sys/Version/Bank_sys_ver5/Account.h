#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include <cstring>

class Account
{
	protected:
		int AccID;
		int Balance;
		char* Customer_Name;
	public:
		Account(int id,int money,char* name);
		Account(const Account& ref);
		Account& operator=(const Account& ref);

		virtual void Deposit(int money);
		int Withdraw(int money);
		virtual void ShowInfo(void) const;
		virtual ~Account();
};

#endif
