#include "006_cal_class.h"

void Calculator::Init(void)
{
	c_add=0;
	c_min=0;
	c_mul=0;
	c_div=0;
}

int Calculator::Add(int x,int y)
{
	c_add++;
	return x+y;
}

int Calculator::Min(int x,int y)
{
	c_min++;
	return x-y;
}

int Calculator::Mul(int x,int y)
{
	c_mul++;
	return x*y;
}

int Calculator::Div(int x,int y)
{
	c_div++;
	return x/y;
}

void Calculator::ShowOpCount(void)
{
	std::cout<<c_add<<','<<c_min<<','<<c_mul<<','<<c_div<<std::endl;
}
