#include<iostream>
#include <ostream>

class Number
{
	private:
		int num;
	public:
		Number(int n):num(n){}
		void Show(){std::cout<<num<<std::endl;}

		Number* operator->()
		{
			return this;
		}

		Number& operator*()
		{
			return *this;
		}
};

class Point
{
	private:
		int xpos,ypos;
	public:
		Point(int x=0,int y=0):xpos(x),ypos(y){}
		~Point(){}
		void SetPos(int x,int y)
		{
			xpos=x;
			ypos=y;
		}
		friend std::ostream& operator<<(std::ostream&,const Point&);
};

std::ostream& operator<<(std::ostream& os,const Point& pos)
{
	os<<"["<<pos.xpos<<","<<pos.ypos<<"]"<<std::endl;
	return os;
}

class SmartPtr
{
	private:
		Point *pptr;
	public:
		SmartPtr(Point *ptr):pptr(ptr){}
		Point& operator*() const {return *pptr;}
		Point* operator->() const {return pptr;}
		~SmartPtr(){delete pptr;}
};

int main(void)
{
	Number num(20);
	num.Show();

	(*num)=30;
	num->Show();
	(*num).Show();

	std::cout<<"-------"<<std::endl;

	SmartPtr sptr1(new Point(1,2));
	SmartPtr sptr2(new Point(3,4));
	SmartPtr sptr3(new Point(5,6));

	std::cout<<*sptr1;
	std::cout<<*sptr2;
	std::cout<<*sptr3;
	
	sptr1->SetPos(10,20);
	sptr2->SetPos(30,40);
	sptr3->SetPos(50,60);

	std::cout<<*sptr1;
	std::cout<<*sptr2;
	std::cout<<*sptr3;

	return 0;
}
