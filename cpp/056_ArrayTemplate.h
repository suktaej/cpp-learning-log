#ifndef __ARRAY_TEMPALTE_H_
#define __ARRAY_TEMPALTE_H_

#include<iostream>
#include<cstdlib>

template<typename T>
class BoundCheckArr
{
	private:
		T* arr;
		int arrlen;
		
		BoundCheckArr(const BoundCheckArr& arr){}
		BoundCheckArr& operator=(const BoundCheckArr& arr){}

	public:
		BoundCheckArr(int len);
		T& operator[](int idx);
		T operator[](int idx) const;
		int GetArrLen() const;
		~BoundCheckArr();
};

template<typename T>
BoundCheckArr<T>::BoundCheckArr(int len):arrlen(len){arr=new T[len];}

template<typename T>
T& BoundCheckArr<T>::operator[](int idx)
{
	if(idx<0||idx>=arrlen)
	{
		std::cout<<"Array index out of bound exception"<<std::endl;
		exit(1);
	}
	return arr[idx];
}

template<typename T>
T BoundCheckArr<T>::operator[](int idx) const
{
	if(idx<0||idx>=arrlen)
	{
		std::cout<<"Array index out of bound exception"<<std::endl;
		exit(1);
	}
	return arr[idx];
}

template<typename T>
int BoundCheckArr<T>::GetArrLen() const {return arrlen;}

template<typename T>
BoundCheckArr<T>::~BoundCheckArr(){delete[] arr;}

#endif
