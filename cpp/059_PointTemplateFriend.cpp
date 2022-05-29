#include<iostream>
#include <ostream>

template<typename T>
class Point
{
	private:
		T xpos,ypos;
	public:
		Point(T x=0,T y=0);
		void Show() const;

		friend Point<int> operator+(const Point<int>&,const Point<int>&);
		friend std::ostream& operator<<(std::ostream& os,const Point<int>& pos);
};

template<typename T>
Point<T>::Point(T x,T y):xpos(x),ypos(y){}

template<typename T>
void Point<T>::Show() const {std::cout<<xpos<<","<<ypos<<std::endl;}

Point<int> operator+(const Point<int>& pos1,const Point<int>& pos2)
{
	return Point<int>(pos1.xpos+pos2.xpos,pos1.ypos+pos2.ypos);
}

std::ostream& operator<<(std::ostream& os,const Point<int>& pos)
{
	os<<pos.xpos<<","<<pos.ypos<<std::endl;
	return os;
}

int main(void)
{
	Point<int> pos1(1,2);
	Point<int> pos2(9,8);
	Point<int> pos3=pos1+pos2;
	std::cout<<pos1<<pos2<<pos3;
	return 0;
}

