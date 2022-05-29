#include<iostream>

class AAA
{
	public:
		void Show() {std::cout<<"AAA exception"<<std::endl;}
};

class BBB:public AAA
{
	public:
		void Show() {std::cout<<"BBB exception"<<std::endl;}
};

class CCC:public BBB
{
	public:
		void Show() {std::cout<<"CCC exception"<<std::endl;}
};

void ExceptionGen(int expn)
{
	if(expn==1)
		throw AAA();
	else if(expn==2)
		throw BBB();
	else
		throw CCC();
}

int main(void)
{
	try
	{
		ExceptionGen(3);
	//	ExceptionGen(2);
	//	ExceptionGen(1);
	}
	catch(CCC& expn)
	{
		std::cout<<"catch(CCC&)"<<std::endl;
		expn.Show();
	}
	catch(BBB& expn)
	{
		std::cout<<"catch(BBB&)"<<std::endl;
		expn.Show();
	}
	catch(AAA& expn)
	{
	std::cout<<"catch(AAA&)"<<std::endl;
		expn.Show();
	}
}
