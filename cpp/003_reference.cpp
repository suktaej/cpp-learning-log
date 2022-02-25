#include<iostream>

void SwapPointer(int *(&ptr1),int *(&ptr2));

int& ReFunc1(int &num);
int ReFunc2(int &num);
int& ReFunc3(int num);	//error

int main(void)
{
	int num1=1;
	int *ptr1=&num1;
	int num2=99;
	int *ptr2=&num2;

	std::cout<<ptr1<<','<<ptr2<<std::endl;
	SwapPointer(ptr1, ptr2);
	std::cout<<ptr1<<','<<ptr2<<std::endl;

	int ref1=10;
	int &ref2=ReFunc1(ref1);
	
	ref1++;
	ref2++;
	std::cout<<ref1<<','<<ref2<<std::endl;

	int ref3=ReFunc2(ref1);

	ref1+=100;
	ref2+=200;
	ref3+=500;
	std::cout<<ref1<<','<<ref2<<','<<ref3<<std::endl;

	const int numb=55;
	const int *ptr=&numb;
	const int *(&rptr)=ptr;

	std::cout<<*ptr<<","<<*rptr<<std::endl;
}

void SwapPointer(int *(&ptr1),int *(&ptr2))
{
	int *temp=ptr2;
	ptr2=ptr1;
	ptr1=temp;
}

int& ReFunc1(int &num)
{
	num++;
	return num;
}

int ReFunc2(int &num)
{
	num++;
	return num;
}

int& ReFunc3(int num)	//error
{
	num++;
	return num;
}
