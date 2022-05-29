#include<iostream>

template<typename T>
class SSM
{
	private:
		static T mem;
	public:
		void AddMem(int num){mem+=num;}
		void Show(){std::cout<<mem<<std::endl;}
};

template<typename T>
T SSM<T>::mem=0;

int main(void)
{
	SSM<int> obj1;
	SSM<int> obj2;
	obj1.AddMem(2);
	obj2.AddMem(20);
	obj1.Show();
	SSM<long> obj3;
	SSM<long> obj4;
	obj3.AddMem(900);
	obj4.AddMem(9000);
	obj4.Show();
	return 0;
}
