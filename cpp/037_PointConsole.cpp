#include<iostream>

class Point
{
	private:
		int xpos,ypos;
	public:
		Point(int x=0,int y=0):xpos(x),ypos(y){}
		
		void Show() const
		{
			std::cout<<"x:"<<xpos<<"\ty:"<<ypos<<std::endl;
		}

	friend std::ostream& operator<<(std::ostream&,const Point&);
	friend std::istream& operator>>(std::istream&,Point&);
};

std::ostream& operator<<(std::ostream& os,const Point& pos)
{
	os<<"x:"<<pos.xpos<<"\ty:"<<pos.ypos<<std::endl;
	return os;
}

std::istream& operator>>(std::istream& is,Point& pos)
{
	is>>pos.xpos>>pos.ypos;
	return is;
}

int main(void)
{
	Point p1(10,20);
	std::cout<<p1;
	Point p2(1,2);
	std::cout<<p2;

	Point p3;
	std::cout<<"insert x,y:";
	std::cin>>p3;
	std::cout<<p3;

	return 0;
}
