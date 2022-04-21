#include<iostream>

class First
{
	public:
		virtual void Show(){std::cout<<"First Class"<<std::endl;}
};

class Second: public First
{
	public:
		virtual void Show(){std::cout<<"Second Class"<<std::endl;}
};

class Third :public Second
{
	public:
		virtual void Show(){std::cout<<"Third Class"<<std::endl;}
};

int main(void)
{
	Third *three=new Third();
	Second *two=three;
	First *one=two;

	one->Show();
	two->Show();
	three->Show();

	three->Second::Show();
	three->First::Show();
	two->First::Show();

	delete three;
	return 0;
}



