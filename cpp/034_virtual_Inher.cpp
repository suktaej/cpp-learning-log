#include<iostream>

class Base
{
	public:
		Base(){std::cout<<"Base const"<<std::endl;}
		void Func(){std::cout<<"Base"<<std::endl;}
};

class Derived_One: virtual public Base
{
	public:
		Derived_One():Base(){std::cout<<"Derived one const"<<std::endl;}
		
		void D_Func1()
		{
			Func();
			std::cout<<"Derived one"<<std::endl;
		}
};

class Derived_Two: virtual public Base
{
	public:
		Derived_Two():Base(){std::cout<<"Derived two const"<<std::endl;}

		void D_Func2()
		{
			Func();
			std::cout<<"Derived two"<<std::endl;
		}
};

class Derived_Last:public Derived_One,public Derived_Two
{
	public:
		Derived_Last():Derived_One(),Derived_Two(){std::cout<<"Last const"<<std::endl;}

		void L_Func()
		{
			D_Func1();
			D_Func2();
			Func();
		}
};

int main(void)
{
	std::cout<<"----------"<<std::endl;
	Derived_Last ldr;
	std::cout<<"----------"<<std::endl;
	ldr.L_Func();

	return 0;
}
