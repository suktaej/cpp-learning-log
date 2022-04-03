#include<iostream>

class Point;

class Point_OP
{
	private:
		int op_cnt;
	public:
		Point_OP():op_cnt(0){}
		Point PointAdd(const Point&, const Point&);
		Point PointSub(const Point&, const Point&);
		~Point_OP()
		{
			std::cout<<"Operation time:"<<op_cnt<<std::endl;
		}
};

class Point
{
	private:
		int x;
		int y;
	public:
		Point(const int &xpos, const int &ypos):x(xpos),y(ypos){}
		friend Point Point_OP::PointAdd(const Point&,const Point&);
		friend Point Point_OP::PointSub(const Point&,const Point&);
		friend void Show(const Point&);
};

Point Point_OP::PointAdd(const Point &pnt1, const Point &pnt2)
{
	op_cnt++;
	return Point(pnt1.x+pnt2.x,pnt1.y+pnt2.y);
}

Point Point_OP::PointSub(const Point &pnt1, const Point &pnt2)
{
	op_cnt++;
	return Point(pnt1.x-pnt2.x,pnt1.y-pnt2.y);
}

int main(void)
{
	Point p1(1,2);
	Point p2(2,4);
	Point_OP op;

	Show(op.PointAdd(p1,p2));
	Show(op.PointSub(p2,p1));
	
	return 0;
}

void Show(const Point& pos)
{
	std::cout<<"x:"<<pos.x<<"\ty:"<<pos.y<<std::endl;
}
