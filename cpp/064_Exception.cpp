#include<iostream>

void Func1(void);
void Func2(void);
void Func3(void);

int main(void)
{
	int num1=10;
	int num2=5;

	try
	{
		if(num1<num2)
			throw num1;
		std::cout<<"progress:"<<num2<<std::endl;

		Func1();
	}
	catch(int expn)
	{
		std::cout<<"catch:"<<expn<<std::endl;
	}
	catch(char expn)
	{
		std::cout<<"char expn"<<std::endl;
	}

	return 0;
}

void Func1(void)
{
	std::cout<<"F1"<<std::endl;
	Func2();
}

void Func2(void)
{
	std::cout<<"F2"<<std::endl;
	Func3();
}

void Func3(void)
{
	std::cout<<"F3"<<std::endl;
	throw -1;
}
