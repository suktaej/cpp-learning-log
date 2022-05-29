#include"068_CarTruck.h"
#include<iostream>

class Simple
{
	public:
		virtual void Show(){std::cout<<"simple class"<<std::endl;}
};

class Complex:public Simple
{
	public:
		void Show(){std::cout<<"Complex class"<<std::endl;}
};

void ShowStr(char* str)
{
	std::cout<<str<<std::endl;
}

void ShowAddResult(int& n1,int& n2)
{
	std::cout<<n1+n2<<std::endl;
}

int main(void)
{
	int num1=20, num2=3;
	double result=static_cast<double>(20)/3;

	const char* name="Hong Gil Dong";
	ShowStr(const_cast<char*>(name));

	const int& num3=100;
	const int& num4=200;
	ShowAddResult(const_cast<int&>(num3),const_cast<int&>(num4));

	Car* pcar1=new Truck(80,200);
	Truck* ptruck1=static_cast<Truck*>(pcar1);

	Car* pcar2=new Car(120);
	Truck* ptruck2=static_cast<Truck*>(pcar2);		//compile OK! but!

	Truck* ptruck3=new Truck(70,150);
	Car* pcar3=dynamic_cast<Car*>(ptruck3);

	int num=0x010203;
	char* ptr=reinterpret_cast<char*>(&num);

	for(int i=0;i<sizeof(num);i++)
		std::cout<<static_cast<int>(*(ptr+i))<<std::endl;

	Simple* sptr=new Complex;
	Complex* cptr=dynamic_cast<Complex*>(sptr);
	cptr->Show();
	return 0;
}
