#ifndef __CAL_CLASS__
#define __CAL_CLASS__

#include <iostream>

class Calculator{

	private:
		int c_add,c_min,c_mul,c_div;
	public:
	void Init();
	int Add(int x,int y);
	int Min(int x,int y);
	int Mul(int x,int y);
	int Div(int x,int y);
	void ShowOpCount();
};

#endif
