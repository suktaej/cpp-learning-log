#include<iostream>

void Devide(int num1,int num2)
{
	try
	{
		if(num2==0)
			throw 0;
		std::cout<<num1/num2<<std::endl;
		std::cout<<num1%num2<<std::endl;
	}
	catch(int expn)
	{
		std::cout<<"first catch"<<std::endl;
		throw;
	}
}

int main(void)
{
	try
	{
		Devide(9,2);
		Devide(4,0);
	}
	catch(int expn)
	{
		std::cout<<"second catch"<<std::endl;
	}
	return 0;
}
