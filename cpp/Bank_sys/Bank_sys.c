#include<stdio.h>
#include<string.h>

#define NAME_LEN 16
#define ACC_LEN 256

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowInfo(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct
{
	int AccID;
	int Balance;
	char Customer_Name[NAME_LEN];
} Account;

Account Accarr[ACC_LEN];
int Accnum=0;

int main(void)
{
	int choice;

	while(1)
	{
		ShowMenu();
		printf("Please choose number>");
		scanf("%d",&choice);
		printf("\n");

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
				ShowInfo();
				break;
			case EXIT:
				return 0;
			default:
				printf("Illegal Selection\n");
		}
	}

	return 0;
}

void ShowMenu(void)
{
	printf("=====Menu=====\n");
	printf("1.Create Account\n");
	printf("2.Deposit\n");
	printf("3.Withdraw\n");
	printf("4.Show State\n");
	printf("5.Exit\n");
}

void MakeAccount(void)
{
	int money;
	char name[NAME_LEN];

	printf("[Make Account]\n");
	printf("Name>");
	scanf("%s",name);
	printf("Deposit Amount>");
	scanf("%d",&money);
	printf("\n");

	Accarr[Accnum].AccID=Accnum;
	Accarr[Accnum].Balance=money;
	strcpy(Accarr[Accnum].Customer_Name,name);

	printf("ID:%d\n",Accarr[Accnum].AccID);
	printf("Name:%s\n",Accarr[Accnum].Customer_Name);
	printf("Balance:%d\n",Accarr[Accnum].Balance);

	Accnum++;
}

void DepositMoney(void)
{
	int money;
	int id;

	while(1)
	{
		printf("[Deposit Money]\n");
		printf("ID>");
		scanf("%d",&id);

		if(id<Accnum&&id>=0)
		{
			printf("Deposit Amount>");
			scanf("%d",&money);
		
			Accarr[id].Balance+=money;
			printf("Deposit Complete\nCurrent Your balance:%d\n",Accarr[id].Balance);
			return;
		}
		else 
			printf("Illegal ID\n");
	}
}

void WithdrawMoney(void)
{
	int money;
	int id;

	while(1)
	{
		printf("[Withdraw Money]\n");
		printf("ID>");
		scanf("%d",&id);

		if(id<Accnum&&id>=0)
		{
			printf("Withdrawal Amount>");
			scanf("%d",&money);
			
			if(Accarr[id].Balance<money)
				printf("A shortage of balance\n");
			else
			{

				Accarr[id].Balance-=money;
				printf("Withdrawal Complete\nCurrent Your balance:%d\n",Accarr[id].Balance);
				return;
			}
		}
		else
			printf("Illegal ID\n");
	}
}

void ShowInfo(void)
{
	int id;

	while(1)
	{
		printf("[INFO]\n");
		printf("ID>");
		scanf("%d",&id);

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
