#ifndef __ARRAY_TEMPLATE_
#define __ARRAY_TEMPLATE_

#include<iostream>
#include<cstdlib>

template<typename T>
class BoundCheackArray
{
	private:
		T* arr;
		int arrlen;
		BoundCheackArray(const BoundCheackArray& arr){}
		BoundCheackArray& operator=(const BoundCheackArray& arr_){}
	public:
		BoundCheackArray(int len);
		T& operator[] (int idx);
		T operator[] (int idx) const;
		int GetArrLen() const;
		~BoundCheackArray();
};

template<typename T>
BoundCheackArray<T>::BoundCheackArray(int len):arrlen(len)
{
	arr=new T[len];
}

template<typename T>
T& BoundCheackArray<T>::operator[](int idx)
{
	if(idx<0||idx>=arrlen)
		exit(1);
	return arr[idx];
}

template<typename T>
T BoundCheackArray<T>::operator[](int idx) const
{
	if(idx<0||idx>=arrlen)
		exit(1);
	return arr[idx];
}

template<typename T>
int BoundCheackArray<T>::GetArrLen() const
{
	return arrlen;
}

template<typename T>
BoundCheackArray<T>::~BoundCheackArray(){delete[] arr;}

#endif
