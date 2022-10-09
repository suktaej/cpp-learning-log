#ifndef __BANKINGEXCEPTION_H__
#define __BANKINGEXCEPTION_H__

#include "Account.h"

class MinusException
{
	private:
		int exVal;
	public:
		MinusException(int val):exVal(val){}
		void ShowExceptionInfo(void) const
		{
			std::cout<<"Amount "<<exVal<<"is not avild"<<std::endl;
		}
};

class InsuffException
{
	private:
		int balance;
		int reqval;
	public:
		InsuffException(int val,int req)
			:balance(val),reqval(req){}
		void ShowExceptionInfo() const
		{
			std::cout<<"Not enough "<<reqval-balance<<"left"<<std::endl;
		}
};

#endif
