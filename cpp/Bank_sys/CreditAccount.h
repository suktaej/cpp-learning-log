#ifndef __CREDIT_ACCOUNT_H__
#define __CREDIT_ACCOUNT_H__

#include "BankingException.h"
#include "NormalAccount.h"

class CreditAccount:public NormalAccount
{
	private:
		int specialRate;
	public:
		CreditAccount(int id,int money,String name,int rate,int spec)
			:NormalAccount(id,money,name,rate),specialRate(spec){}
		virtual void Deposit(int money)
		{
			if(money<0)
				throw MinusException(money);

			NormalAccount::Deposit(money);
			Account::Deposit(money*(specialRate/100.0));
		}	
		virtual void ShowInfo(void) const
		{
			std::cout<<"------[Credit ID]-------"<<std::endl;
			std::cout<<"ID:\t\t"<<AccID<<std::endl;
			std::cout<<"Name:\t\t"<<Customer_Name<<std::endl;
			std::cout<<"Balance:\t"<<Balance<<std::endl;
			std::cout<<"Rate:\t\t"<<interRate<<"%"<<std::endl;
			std::cout<<"CreditLevel:\t"<<specialRate<<"%"<<std::endl;
			std::cout<<"------------------------"<<std::endl;
		}
};
#endif
