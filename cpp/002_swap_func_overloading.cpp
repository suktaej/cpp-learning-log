#include "002_swap_func_overloading.h"

int main(void)
{
	int num1=10, num2=90;
	
	swap(&num1,&num2);
	std::cout<<num1<<' '<<num2<<std::endl;

	char ch1='A', ch2='Z';

	swap(&ch1,&ch2);
	std::cout<<ch1<<' '<<ch2<<std::endl;

	double dbl1=1.111, dbl2=9.999;

	swap(&dbl1,&dbl2);
	std::cout<<dbl1<<' '<<dbl2<<std::endl;
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void swap(char *a,char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void swap(double *a,double *b)
{
	double temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
