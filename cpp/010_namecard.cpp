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
		std::string name;
		std::string office;
		std::string phone;
		int pos;
	public:
		NameCard(const std::string &input_name,const std::string &input_office,const std::string &input_phone,int input_pos):name(input_name),office(input_office),phone(input_phone),pos(input_pos){}
		void ShowNameCard(void)
		{
			std::cout<<"name:"<<name<<std::endl;
			std::cout<<"office:"<<office<<std::endl;
			std::cout<<"phone:"<<phone<<std::endl;
			std::cout<<"position:";
			COMP_POS::ShowPos(pos);
			std::cout<<std::endl;
		}
		~NameCard(){}
};

int main(void)
{
	NameCard manA("Lee","Off_A","123456789",COMP_POS::CLERK);
	NameCard manB("Kim","Off_B","2468",COMP_POS::ASSIST);
	NameCard *manC = new NameCard("Pack","Off_C","13579",COMP_POS::CLERK);
	
	manA.ShowNameCard();
	manB.ShowNameCard();
	manC->ShowNameCard();

	delete manC;

	return 0;
}
