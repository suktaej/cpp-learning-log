#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdlib>

#define NAME_LEN 16
#define ACC_LEN 256

//void ShowMenu(void);
//void MakeAccount(void);
//void DepositMoney(void);
//void WithdrawMoney(void);
//void ShowAll(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
enum {LEV_A=7, LEV_B=4, LEV_C=2};
enum {NORMAL=1, CREDIT=2};

class Account
{
	protected:
		int AccID;
		int Balance;
		char* Customer_Name;
	public:
		Account(int id,int money,char* name):AccID(id),Balance(money)
		{
			Customer_Name=new char[strlen(name)+1];
			strcpy(Customer_Name,name);
		}
		Account(const Account& ref):AccID(ref.AccID),Balance(ref.Balance)
		{
			Customer_Name=new char[strlen(ref.Customer_Name)+1];
			strcpy(Customer_Name,ref.Customer_Name);
		}

		virtual void Deposit(int money){Balance+=money;}

		int Withdraw(int money)
		{
			if(Balance<money)
				return 0;

			Balance-=money;
			return money;
		}
		virtual void ShowInfo(void) const
		{
			std::cout<<"------------------------"<<std::endl;
			std::cout<<"ID:\t\t"<<AccID<<std::endl;
			std::cout<<"Name:\t\t"<<Customer_Name<<std::endl;
			std::cout<<"Balance:\t"<<Balance<<std::endl;
			std::cout<<"------------------------"<<std::endl;
		}
		~Account()
		{
			if(Customer_Name!=NULL)
				delete[] Customer_Name;
		}
};

class NormalAccount:public Account
{
	protected:
		int interRate;
	public:
		NormalAccount(int id,int money,char* name,int rate):Account(id,money,name),interRate(rate){}
		virtual void Deposit(int money)
		{
			Account::Deposit(money);
			Account::Deposit(money*(interRate/100.0));
		}
		virtual void ShowInfo(void) const
		{
			std::cout<<"------[Normal ID]--------"<<std::endl;
			std::cout<<"ID:\t\t"<<AccID<<std::endl;
			std::cout<<"Name:\t\t"<<Customer_Name<<std::endl;
			std::cout<<"Balance:\t"<<Balance<<std::endl;
			std::cout<<"Rate:\t\t"<<interRate<<"%"<<std::endl;
			std::cout<<"------------------------"<<std::endl;
		}
};

class CreditAccount:public NormalAccount
{
	private:
		int specialRate;
	public:
		CreditAccount(int id,int money,char* name,int rate,int spec):NormalAccount(id,money,name,rate),specialRate(spec){}
		virtual void Deposit(int money)
		{
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

class AccountHandler
{
	private:
		Account* Accarr[ACC_LEN];
		int Accnum;
	protected:
		void MakeNormalAccount(void);
		void MakeCreditAccount(void);
	public:
		AccountHandler();
		void ShowMenu(void) const;
		void MakeAccount(void);
		void DepositMoney(void);
		void WithdrawMoney(void);
		void ShowAll(void) const;
		~AccountHandler();
};

void AccountHandler::ShowMenu(void) const
{
	std::cout<<"=====Menu====="<<std::endl;
	std::cout<<"1.Create Account"<<std::endl;
	std::cout<<"2.Deposit"<<std::endl;
	std::cout<<"3.Withdraw"<<std::endl;
	std::cout<<"4.Show All State"<<std::endl;
	std::cout<<"5.Exit"<<std::endl;
}

void AccountHandler::MakeAccount(void)
{
	int sel;
	
	std::cout<<"[Select Account type]"<<std::endl;
	while(1)
	{
		std::cout<<"1.NormalAccount\t2.CreditAccount"<<std::endl;
		std::cout<<"Account type>"; std::cin>>sel;
		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(NAME_LEN,'\n');
			std::cout<<"***Please input the number***"<<std::endl;
			continue;
		}

		if(sel==1)
		{
			MakeNormalAccount();
			break;
		}
		else if(sel==2)
		{
			MakeCreditAccount();
			break;
		}
		else
			std::cout<<"***Incorrect Number***"<<std::endl;
	}
}

void AccountHandler::MakeNormalAccount(void)
{
	int money,rate;
	char name[NAME_LEN];

	std::cout<<"[Make Normal Account]"<<std::endl;
	std::cout<<"Name>";std::cin>>name;

	while(1)
	{
		std::cout<<"Balance>";std::cin>>money;
		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(NAME_LEN,'\n');
			std::cout<<"***Please Input The Number***"<<std::endl;
		}
		else
		{
			while(1)
			{
				std::cout<<"Rate>";std::cin>>rate;
				if(std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(NAME_LEN,'\n');
					std::cout<<"***Please Input The Number***"<<std::endl;
					continue;
				}
				
				Accarr[Accnum]=new NormalAccount(Accnum,money,name,rate);
				Accarr[Accnum]->ShowInfo();
				Accnum++;
				break;
			}
			break;
		}
	}
	std::cout<<std::endl;
}

void AccountHandler::MakeCreditAccount(void)
{
	int money,rate,credit_lev;
	char name[NAME_LEN];

	std::cout<<"[Make Credit Account]"<<std::endl;
	std::cout<<"Name>";std::cin>>name;

	while(1)
	{
		std::cout<<"Balance>";std::cin>>money;
		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(NAME_LEN,'\n');
			std::cout<<"***Please Input The Number***"<<std::endl;
		}
		else
		{
			while(1)
			{
				std::cout<<"Rate>";std::cin>>rate;
			
				if(std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(NAME_LEN,'\n');
					std::cout<<"***Please Input The Number***"<<std::endl;
				}
				else
				{
					while(1)
					{
						std::cout<<"credit Level(1 to A\t2 to B\t3 to C)>";std::cin>>credit_lev;

						if(std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore(NAME_LEN,'\n');
							std::cout<<"***Please Input The Number***"<<std::endl;
							continue;
						}
						
						switch(credit_lev)
						{
							case 1:
								Accarr[Accnum]=new CreditAccount(Accnum,money,name,rate,LEV_A);
								break;
							case 2:
								Accarr[Accnum]=new CreditAccount(Accnum,money,name,rate,LEV_B);
								break;
							case 3:
								Accarr[Accnum]=new CreditAccount(Accnum,money,name,rate,LEV_C);
								break;
							default:
								std::cout<<"***Incorrect number***"<<std::endl;
						}
						break;
					}
					break;
				}
			}
			Accarr[Accnum]->ShowInfo();
			Accnum++;
			break;
		}
	}
	std::cout<<std::endl;
}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;

	std::cout<<"[Deposit Money]"<<std::endl;

	while(1)
	{
		std::cout<<"ID>";std::cin>>id;

		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(NAME_LEN,'\n');
			std::cout<<"***Please Input The Number***"<<std::endl;
		}
		else
		{
			if(id<0||id>=Accnum)
				std::cout<<"***Incorrect ID***"<<std::endl;
			else
				break;
		}
	}

	while(1)
	{
		std::cout<<"Money Amount>";std::cin>>money;

		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(NAME_LEN,'\n');
			std::cout<<"***Please Input The Number***"<<std::endl;
		}
		else
			break;
	}

	Accarr[id]->Deposit(money);
	std::cout<<"Deposit Complete"<<std::endl;
	Accarr[id]->ShowInfo();
}

void AccountHandler::WithdrawMoney(void)
{
	int id;
	int money;

	std::cout<<"[Withdrawal Money]"<<std::endl;
	
	while(1)
	{
		std::cout<<"ID>";std::cin>>id;

		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(NAME_LEN,'\n');
			std::cout<<"***Please Input The Number***"<<std::endl;
		}
		else
		{
			if(id<0||id>=Accnum)
				std::cout<<"***Incorrect ID***"<<std::endl;
			else
				break;
		}
	}

	while(1)
	{
		std::cout<<"Money Amount>";std::cin>>money;

		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(NAME_LEN,'\n');
			std::cout<<"***Please Input The Number***"<<std::endl;
		}
		else
		{
			if(Accarr[id]->Withdraw(money)==0)
				std::cout<<"***A shortage of balance***"<<std::endl;
			else
				break;
		}
	}

	std::cout<<"Withdrawal Complete"<<std::endl;
	Accarr[id]->ShowInfo();
	return;
}
void AccountHandler::ShowAll(void) const
{
	for(int i=0;i<Accnum;i++)
		Accarr[i]->ShowInfo();
}

AccountHandler::AccountHandler():Accnum(0){}
AccountHandler::~AccountHandler()
{
	for(int i=0;i<Accnum;i++)
		delete Accarr[i];
}

int main(void)
{
	AccountHandler manager;
	int choice;

	while(1)
	{
		manager.ShowMenu();
		while(1)
		{
			std::cout<<"Please choose number>";
			std::cin>>choice;

			if(std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(NAME_LEN,'\n');
				std::cout<<"***Please Input The Number***"<<std::endl;
			}
			else
				break;
		}
		
		switch(choice)
		{
			case MAKE:
				manager.MakeAccount();
				break;
			case DEPOSIT:
				manager.DepositMoney();
				break;
			case WITHDRAW:
				manager.WithdrawMoney();
				break;
			case INQUIRE:
				manager.ShowAll();
				break;
			case EXIT:
				return 0;
			default:
				std::cout<<"***Incorrect Number***"<<std::endl;
		}
	}
	return 0;
}
