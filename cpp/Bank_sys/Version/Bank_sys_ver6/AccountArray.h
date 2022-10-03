#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "Account.h"

#define MAX_ARRAY_LEN 100

class BoundCheckAccountPtrArray
{
	private:
		Account **arr;
		int arrlen;
		BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr){}
		BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr){}
	public:
		BoundCheckAccountPtrArray(int len=MAX_ARRAY_LEN);
		Account*& operator[](int idx);
		Account* operator[](int idx) const;
		int GetArrLen() const;
		~BoundCheckAccountPtrArray();
};
#endif
