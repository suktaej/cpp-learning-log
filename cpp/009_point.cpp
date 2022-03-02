#include"009_point.h"
#include<iostream>

/*Point::Point(const int &x,const int &y)
{
	xpos=x;
	ypos=y;
}
*/

int Point::GetX(void) const {return xpos;}
int Point::GetY(void) const {return ypos;}

bool Point::SetX(int x)
{
	if(0>x||x>100)
	{
		std::cout<<"out of scope"<<std::endl;
		return false;
	}
	xpos=x;
	return true;
}

bool Point::SetY(int y)
{
	if(0>y||y>100)
	{
		std::cout<<"out of scope"<<std::endl;
		return false;
	}
	ypos=y;
	return true;
}
