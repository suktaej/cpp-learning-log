#include<iostream>
#include"055_PointTemplate.h"

template<typename T>
Point<T>::Point(T x,T y):xpos(x),ypos(y){}

template<typename T>
void Point<T>::Show() const
{
	std::cout<<xpos<<","<<ypos<<std::endl;
}
