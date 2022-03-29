#include <iostream>
#include <cstring>

namespace COMP_POS
{
	enum
	{
		CLERK,SENIOR,ASSIST,MANAGER
	};

	void ShowPos(int num)
	{
		switch(num)
		{
			case CLERK:
				std::cout<<"clerk"<<std::endl;
				break;
			case SENIOR:
				std::cout<<"senior"<<std::endl;
				break;
			case ASSIST:
				std::cout<<"assist"<<std::endl;
				break;
			case MANAGER:
				std::cout<<"manager"<<std::endl;
				break;
		}
	}
}
class NameCard
{
	private:
		int pos;
		char *name;
		char *company;
		char *phone;
	public:
		NameCard(const char* name,const char* company,const char* phone,int pos):pos(pos)
		{
			this->name=new char[strlen(name)+1];
			this->company=new char[strlen(company)+1];
			this->phone=new char[strlen(phone)+1];
			strcpy(this->name,name);
			strcpy(this->company,company);
			strcpy(this->phone,phone);
		}

		NameCard(const NameCard& copy):pos(copy.pos)
		{
			name=new char[strlen(copy.name)+1];
			company=new char[strlen(copy.company)+1];
			phone=new char[strlen(copy.phone)+1];
			strcpy(name,copy.name);
			strcpy(company,copy.company);
			strcpy(phone,copy.phone);
		}

		void ShowNameCard(void)
		{
			std::cout<<"name:"<<name<<std::endl;
			std::cout<<"office:"<<company<<std::endl;
			std::cout<<"phone:"<<phone<<std::endl;
			std::cout<<"position:";
			COMP_POS::ShowPos(pos);
			std::cout<<std::endl;
		}
		~NameCard()
		{
			delete []name;
			delete []company;
			delete []phone;
		}
};

int main(void)
{
	NameCard manA("Lee","Off_A","123456789",COMP_POS::CLERK);
	NameCard manB("Kim","Off_B","2468",COMP_POS::ASSIST);
	NameCard *manC = new NameCard("Pack","Off_C","13579",COMP_POS::CLERK);
	NameCard manD=manA;
	NameCard manE=manB;

	manA.ShowNameCard();
	manB.ShowNameCard();
	manC->ShowNameCard();
	manD.ShowNameCard();
	manE.ShowNameCard();

	delete manC;

	return 0;
}
