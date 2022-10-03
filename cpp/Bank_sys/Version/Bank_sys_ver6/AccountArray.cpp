#include "Account.h"
#include "BankingCommonDecl.h"
#include "AccountArray.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len):arrlen(len)
{
	arr=new Account*[len];
}

Account*& BoundCheckAccountPtrArray::operator[](int idx)
{
	if(idx<0||idx>=arrlen)
	{
		std::cout<<"Array index out of bound exception"<<std::endl;
		exit(1);
	}
	return arr[idx];
}

Account* BoundCheckAccountPtrArray::operator[](int idx) const
{
	if(idx<0||idx>=arrlen)
	{
		std::cout<<"Array index out of bound exception"<<std::endl;
		exit(1);
	}
	return arr[idx];
}

int BoundCheckAccountPtrArray::GetArrLen() const
{
	return arrlen;
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray()
{
	delete []arr;
}
