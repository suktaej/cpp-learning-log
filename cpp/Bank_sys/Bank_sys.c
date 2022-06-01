#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define NAME_LEN 16
#define ACC_LEN 256

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowInfo(void);
void ShowAll(void);

int DigitCheck(char*);

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, ALLVIEW, EXIT};

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
	char* choice_str;

	choice_str=malloc(sizeof(char));

	while(1)
	{
		ShowMenu();
		printf("Please choose number>");
		scanf("%s",choice_str);
		while(getchar()!='\n'){}

		if(DigitCheck(choice_str))
			choice=strtol(choice_str,NULL,10);
		else
		{
			printf("***Illegal Selection***\n");
			continue;
		}
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
			case ALLVIEW:
				ShowAll();
				break;
			case EXIT:
				return 0;
			default:
				printf("Illegal Selection\n");
		}
	}

	free(choice_str);
	return 0;
}

void ShowMenu(void)
{
	printf("=====Menu=====\n");
	printf("1.Create Account\n");
	printf("2.Deposit\n");
	printf("3.Withdraw\n");
	printf("4.Show State\n");
	printf("5.Show All State\n");
	printf("6.Exit\n");
}

void MakeAccount(void)
{
	int money;
	char* money_str;
	char name[NAME_LEN];

	money_str=malloc(sizeof(char));

	printf("[Make Account]\n");
	printf("Name>");
	scanf("%s",name);
	while(getchar()!='\n'){}

	while(1)
	{
		printf("Deposit Amount>");
		scanf("%s",money_str);
		while(getchar()!='\n'){}

		if(DigitCheck(money_str))
		{
			money=strtol(money_str,NULL,10);
			break;
		}
		else
			printf("***Illegal Selection***\n");
	}
	printf("\n");

	Accarr[Accnum].AccID=Accnum;
	Accarr[Accnum].Balance=money;
	strcpy(Accarr[Accnum].Customer_Name,name);

	printf("ID:%d\n",Accarr[Accnum].AccID);
	printf("Name:%s\n",Accarr[Accnum].Customer_Name);
	printf("Balance:%d\n",Accarr[Accnum].Balance);

	Accnum++;
	free(money_str);
}

void DepositMoney(void)
{
	int money;
	int id;
	char* money_str;
	char* id_str;

	money_str=malloc(sizeof(char));
	id_str=malloc(sizeof(char));

	printf("[Deposit Money]\n");

	while(1)
	{
		while(1)
		{
			printf("ID>");
			scanf("%s",id_str);
			while(getchar()!='\n'){}

			if(DigitCheck(id_str))
			{
				id=strtol(id_str,NULL,10);
				break;
			}
			else
				printf("***Illegal Selection***\n");
		}

		if(id<Accnum&&id>=0)
		{
			while(1)
			{
				printf("Money Amount>");
				scanf("%s",money_str);
				while(getchar()!='\n'){}

				if(DigitCheck(money_str))
				{
					money=strtol(money_str,NULL,10);
					break;
				}
				else
					printf("***Illegal Selection***\n");
			}

			Accarr[id].Balance+=money;
			printf("Deposit Complete\nCurrent Your balance:%d\n",Accarr[id].Balance);
			return;
		}
		else 
			printf("***Illegal ID***\n");
	}
	free(id_str);
	free(money_str);
}

void WithdrawMoney(void)
{
	int id,money;

	char* money_str;
	char* id_str;

	money_str=malloc(sizeof(char));
	id_str=malloc(sizeof(char));

	printf("[Withdraw Money]\n");
	
	while(1)
	{
		while(1)
		{
			printf("ID>");
			scanf("%s",id_str);
			while(getchar()!='\n'){}

			if(DigitCheck(id_str))
			{
				id=strtol(id_str,NULL,10);
				break;
			}
			else
				printf("***Illegal Selection***\n");
		}

		if(id<Accnum&&id>=0)
		{
			while(1)
			{
				printf("Withdrawal Amount>");
				scanf("%s",money_str);
				while(getchar()!='\n'){}
				
				if(DigitCheck(money_str))
				{
					money=strtol(money_str,NULL,10);
					break;
				}
				else
					printf("***Illegal Selection***\n");
			}

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
			printf("***Illegal ID***\n");
	}
	free(money_str);
	free(id_str);
}

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

void ShowAll(void)
{
	int id;
	
	for(id=0;id<Accnum;id++)
	{
		printf("----------------------\n");
		printf("ID:%d\n",Accarr[id].AccID);
		printf("Name:%s\n",Accarr[id].Customer_Name);
		printf("Balance:%d\n",Accarr[id].Balance);
		printf("----------------------\n");
	}
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
