#ifndef __RECTANGLE_H__
#define __RECTANGEL_H__

#include"009_point.h"

class Rectangle
{
	private:
		Point p1,p2;
	public:
		Rectangle(const int &x1,const int &y1,const int &x2,const int &y2):p1(x1,y1),p2(x2,y2) { }
		void Show(void) const;
		~Rectangle() { }
};

#endif
