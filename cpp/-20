#include<iostream>

class Point
{
	private:
		int xpos,ypos;
	public:
		Point(int x=0,int y=0):xpos(x),ypos(y){}
		Point operator+(const Point& pos) const {return Point(pos.xpos+xpos,pos.ypos+ypos);}
		friend std::ostream& operator<<(std::ostream&,const Point&);
};

std::ostream& operator<<(std::ostream& os,const Point& pos)
{
	os<<"["<<pos.xpos<<","<<pos.ypos<<"]"<<std::endl;
	return os;
}

class Adder
{
	public:
		int operator()(const int &n1,const int &n2){return n1+n2;}
		double operator()(const double &d1,const double &d2){return d1+d2;}
		Point operator()(const Point &p1,const Point &p2){return p1+p2;}
};

int main(void)
{
	Adder ad;
	std::cout<<ad(1,2)<<std::endl;
	std::cout<<ad(1.5,2.4)<<std::endl;
	std::cout<<ad(Point(3,4),Point(4,3));
	return 0;
}
