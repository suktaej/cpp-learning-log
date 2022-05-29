#include<iostream>
#include<cstring>

class AccountException
{
	public:
		virtual void Show()=0;
};

class DepositException: public AccountException
{
	private:
		int reqDep;
	public:
		DepositException(int money):reqDep(money){}
		void Show(){std::cout<<"exception message: "<<reqDep<<" can not input"<<std::endl;}
};

class WithdrawException: public AccountException
{
	private:
		int balance;
	public:
		WithdrawException(int money):balance(money){}
		void Show(){std::cout<<"exception message: "<<balance<<" balance is negative"<<std::endl;}
};

class Account
{
	private:
		char AccNum[50];
		int balance;
	public:
		Account(char *acc,int money):balance(money)
		{
			strcpy(AccNum,acc);
		}
		void Deposit(int money) throw(DepositException)
		{
			if(money<0)
			{
				DepositException expn(money);
				throw expn;
			}
			balance+=money;
		}
		void Withdraw(int money) throw(WithdrawException)
		{
			if(money>balance)
				throw WithdrawException(balance);
			balance-=money;
		}
		void Show(){std::cout<<"balance:"<<balance<<std::endl;}
};

int main(void)
{
	Account acc1("12345",5000);

	try
	{
		acc1.Deposit(2000);
		acc1.Deposit(-2000);
	}
//	catch(DepositException &expn)
	catch(AccountException& expn)
	{
		expn.Show();
	}
	acc1.Show();

	try
	{
		acc1.Withdraw(3000);
		acc1.Withdraw(5000);
	}
//	catch(WithdrawException& expn)
	catch(AccountException& expn)
	{
		expn.Show();
	}
	acc1.Show();
	return 0;
}

