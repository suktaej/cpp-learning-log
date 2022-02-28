#include<iostream>
#include"009_rectangle.h"

Rectangle::Rectangle(const int &x1,const int &y1,const int &x2,const int &y2):p1(x1,y1),p2(x2,y2)
{ }

void Rectangle::Show(void) const
{
	std::cout<<"left up:"<<p1.GetX()<<','<<p1.GetY()<<std::endl;
	std::cout<<"right bottom"<<p2.GetX()<<'.'<<p2.GetY()<<std::endl;
}
