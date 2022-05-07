#include<iostream>

template <typename rtype>
rtype Add(rtype num1, rtype num2){return num1+num2;}

template <class T1,class T2>
void Show(double num)
{
	std::cout<<(T1)num<<" "<<(T2)num<<std::endl;
}

int main(void)
{
	std::cout<<Add<int>(15,20)<<std::endl;
	std::cout<<Add<double>(1.1,5.2)<<std::endl;
	std::cout<<Add<int>(1.1,5.2)<<std::endl;
	std::cout<<Add<double>(15.42,20.34)<<std::endl;

	Show<char,int>(65);
	Show<char,int>(67);
	Show<char,double>(69.4);
	Show<short,double>(71.3);

	return 0;
}
