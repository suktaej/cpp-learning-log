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
		std::string Customer_Name;	//char* Customer_Name;

	public:
		Account(int id,int money,std::string name);
//		Account(int id,int money,char* name);
//		Account(const Account& ref);
//		Account& operator=(const Account& ref);

		virtual void Deposit(int money);
		int Withdraw(int money);
		virtual void ShowInfo(void) const;
//		virtual ~Account();
};

#endif
