#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdlib>

#define NAME_LEN 16
#define ACC_LEN 256

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowInfo(void);
void ShowAll(void);

int DigitCheck(char*);

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account
{
	private:
		int AccID;
		int Balance;
		char* Customer_Name;
	public:
		Account(int id,int money,char* name):AccID(id),Balance(money)
		{
			Customer_Name=new char[strlen(name)+1];
			strcpy(Customer_Name,name);
		}
		void Deposit(int money){Balance+=money;}
		int Withdraw(int money)
		{
			if(Balance<money)
				return 0;

			Balance-=money;
			return money;
		}
		void ShowInfo(void)
		{
			std::cout<<"------------------------"<<std::endl;
			std::cout<<"ID:\t\t"<<AccID<<std::endl;
			std::cout<<"Name:\t\t"<<Customer_Name<<std::endl;
			std::cout<<"Balance:\t"<<Balance<<std::endl;
			std::cout<<"------------------------"<<std::endl;
		}
		~Account(){delete[] Customer_Name;}
};

Account* Accarr[ACC_LEN];
int Accnum=0;

int main(void)
{
	int choice;
	//char* choice_str=new char;
	//choice_str=malloc(sizeof(char));

	while(1)
	{
		ShowMenu();
		std::cout<<"Please choose number>";
		std::cin>>choice;
/*		while(getchar()!='\n'){}

		if(DigitCheck(choice_str))
			choice=strtol(choice_str,NULL,10);
		else
		{
			printf("***Illegal Selection***\n");
			continue;
		}
		printf("\n");
*/
		switch(choice)
		{
			case MAKE:
				MakeAccount();
				break;
			case DEPOSIT:
				DepositMoney();
				break;
			case WITHDRAW:
				WithdrawMoney();
				break;
			case INQUIRE:
				ShowAll();
				break;
			case EXIT:
				for(int i=0;i<Accnum;i++)
					delete[] Accarr[i];
				return 0;
			default:
				std::cout<<"***Illegal Selection***"<<std::endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	std::cout<<"=====Menu====="<<std::endl;
	std::cout<<"1.Create Account"<<std::endl;
	std::cout<<"2.Deposit"<<std::endl;
	std::cout<<"3.Withdraw"<<std::endl;
	std::cout<<"4.Show All State"<<std::endl;
	std::cout<<"5.Exit"<<std::endl;
}

void MakeAccount(void)
{
	int money;
	char name[NAME_LEN];

	std::cout<<"[Make Account]"<<std::endl;
	std::cout<<"Name>";std::cin>>name;
	std::cout<<"Balance>";std::cin>>money;
	std::cout<<std::endl;

	Accarr[Accnum]=new Account(Accnum,money,name);
	Accarr[Accnum]->ShowInfo();
	Accnum++;
}

void DepositMoney(void)
{
	int money;
	int id;

	std::cout<<"[Deposit Money]"<<std::endl;
	std::cout<<"ID>";std::cin>>id;
	std::cout<<"Money Amount>";std::cin>>money;

	if(id<0||id>Accnum)
	{
		std::cout<<"***Incorrect ID***"<<std::endl;
		return;
	}

	Accarr[id]->Deposit(money);
	std::cout<<"Deposit Complete"<<std::endl;
	Accarr[id]->ShowInfo();
}
void WithdrawMoney(void)
{
	int id;
	int money;

	std::cout<<"[Withdrawal Money]"<<std::endl;
	std::cout<<"ID>";std::cin>>id;
	std::cout<<"Money Amount>";std::cin>>money;

	if(id<0||id>Accnum)
	{
		std::cout<<"***Incorrect ID***"<<std::endl;
		return;
	}
	
	if(Accarr[id]->Withdraw(money)==0)
	{
		std::cout<<"***A shortage of balance***"<<std::endl;
		return;
	}
	
	std::cout<<"Withdrawal Complete"<<std::endl;
	Accarr[id]->ShowInfo();
	return;
}
/*
void ShowInfo(void)
{
	int id;

	while(1)
	{
		printf("[INFO]\n");
		printf("ID>");
		scanf("%d",&id);
		while(getchar()!='\n'){}

		if(id<Accnum&&id>=0)
		{
			printf("ID:%d\n",Accarr[id].AccID);
			printf("Name:%s\n",Accarr[id].Customer_Name);
			printf("Balance:%d\n",Accarr[id].Balance);
			return;
		}
		else
			printf("Illegal ID\n");
	}
}
*/
void ShowAll(void)
{
	for(int i=0;i<Accnum;i++)
		Accarr[i]->ShowInfo();
}

int DigitCheck(char* str)
{
	int i;

	for(i=0;i<strlen(str);i++)
	{
		if(isdigit(str[i])==0)
			return 0;
	}
	return 1;
}
