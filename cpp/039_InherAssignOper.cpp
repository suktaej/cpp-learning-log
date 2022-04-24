#include<iostream>

class First
{
	private:
		int n1,n2;
	public:
		First(int i1=0,int i2=0):n1(i1),n2(i2){}

		void Show() const {std::cout<<n1<<"\t"<<n2<<std::endl;}
		First& operator=(const First& ref)
		{
			std::cout<<"First& oper="<<std::endl;
			n1=ref.n1;
			n2=ref.n2;
			return *this;
		}
};

class Second:public First
{
	private:
		int n3,n4;
	public:
		Second(int i1,int i2,int i3,int i4):First(i1,i2),n3(i3),n4(i4){}
		
		void Show()
		{
			First::Show();
			std::cout<<n3<<"\t"<<n4<<std::endl;
		}
		
		Second& operator=(const Second& ref)
		{
			std::cout<<"Second& oper="<<std::endl;
			First::operator=(ref);
			n3=ref.n3;
			n4=ref.n4;
			return *this;
		}
};

int main(void)
{
	Second s1(111,222,333,444);
	Second s2(0,0,0,0);
	s2=s1;
	s2.Show();

	return 0;
}
