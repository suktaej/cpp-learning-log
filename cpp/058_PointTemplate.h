#ifndef __POINT_TEMPLATE_H_
#define __POINT_TEMPLATE_H_
#include<iostream>

template<typename T>
class Point
{
	private:
		T xpos,ypos;
	public:
		Point(T x=0,T y=0);
		void SetPos(T x,T y)
		{
			xpos=x;
			ypos=y;
		}
		void Show() const;
};

template<typename T>
Point<T>::Point(T x,T y):xpos(x),ypos(y){}

template<typename T>
void Point<T>::Show() const {std::cout<<xpos<<","<<ypos<<std::endl;}

#endif
