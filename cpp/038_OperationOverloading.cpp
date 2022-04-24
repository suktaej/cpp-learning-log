#include<iostream>

class First
{
	private:
		int n1,n2;
	public:
		First(int i1=0 ,int i2=0):n1(i1),n2(i2){}
		void Show(){std::cout<<n1<<"\t"<<n2<<std::endl;}
};

class Second
{
	private:
		int n3,n4;
	public:
		Second(int i3=0, int i4=0):n3(i3),n4(i4){}
		void Show(){std::cout<<n3<<"\t"<<n4<<std::endl;}

		Second& operator=(const Second& ref)
		{
			std::cout<<"Second& operator=()"<<std::endl;
			n3=ref.n3;
			n4=ref.n4;
			return *this;
		}
};

int main(void)
{
	First f1(11,22);
	First f2;
	Second s1(33,44);
	Second s2;

	f2=f1;
	s2=s1;

	f2.Show();
	s2.Show();

	First fob1,fob2;
	Second sob1,sob2;
	fob1=fob2=f2;
	sob1=sob2=s2;

	fob1.Show();
	fob2.Show();
	sob1.Show();
	sob2.Show();

	return 0;
}

