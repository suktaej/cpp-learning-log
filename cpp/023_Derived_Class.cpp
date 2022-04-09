#include<iostream>

class BaseC
{
	private:
		int bnum;
	public:
		BaseC():bnum(10)
		{
			std::cout<<"base class"<<std::endl;
		}
		BaseC(int num):bnum(num)
		{
			std::cout<<"base class para"<<std::endl;
		}
		~BaseC()
		{
			std::cout<<"base destructor"<<std::endl;
		}
		void ShowBase()
		{
			std::cout<<"base num:"<<bnum<<std::endl;
		}
};

class DerivedC: public BaseC
{
	private:
		int dnum;
	public:
		DerivedC():dnum(100)
		{
			std::cout<<"derived class"<<std::endl;
		}
		DerivedC(int num):dnum(num)
		{
			std::cout<<"derived class para"<<std::endl;
		}
		DerivedC(int n1,int n2):BaseC(n1),dnum(n2)
		{
			std::cout<<"derived class call base class"<<std::endl;
		}
		~DerivedC()
		{
			std::cout<<"derived destructor"<<std::endl;
		}
		void ShowDer()
		{
			ShowBase();
			std::cout<<"dnum:"<<dnum<<std::endl;
		}
};

int main(void)
{
	DerivedC dr1;
	dr1.ShowDer();

	DerivedC dr2(50);
	dr2.ShowDer();

	DerivedC dr3(70,90);
	dr3.ShowDer();

	return 0;
}
