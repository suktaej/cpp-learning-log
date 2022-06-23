#include "BankingCommonDecl.h"
#include "AccountHandler.h"

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

