#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "CreditAccount.h"

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
	//char name[NAME_LEN];
	String name;

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
	//char name[NAME_LEN];
	String name;

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
						std::cout<<"credit Level(1toA\t2toB\t3toC)>";std::cin>>credit_lev;

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
	std::cout<<"ID>";std::cin>>id;
	
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

	while(true)
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
