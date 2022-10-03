#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include <cstring>

typedef std::string String;

class Account
{
	protected:
		int AccID;
		int Balance;
		String Customer_Name;

	public:
		Account(int id,int money,String name);
		virtual void Deposit(int money);
		int Withdraw(int money);
		virtual void ShowInfo(void) const;
};

#endif
