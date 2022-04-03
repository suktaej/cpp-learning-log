#include<iostream>

class Sample
{
	private:
		int num1;
		mutable int num2;
	public:
		Sample(int n1,int n2):num1(n1),num2(n2){}
		void Show() const
		{
			std::cout<<num1<<'\t'<<num2<<std::endl;
		}
		void CopyNum() const
		{
			num2=num1;
		}
};

int main(void)
{
	Sample sm(1,2);
	sm.Show();
	sm.CopyNum();
	sm.Show();

	return 0;
}

