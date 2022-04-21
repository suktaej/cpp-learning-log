#include<iostream>
#include<cstring>

class Rectangle
{
	private:
		int x,y;
	public:
		Rectangle(int inx,int iny):x(inx),y(iny){}

		void Show()
		{
			std::cout<<"x:"<<x<<std::endl;
			std::cout<<"y:"<<y<<std::endl;
		}
};

class Square: public Rectangle
{
	public:
		Square(int in):Rectangle(in,in){}

		void Show()
		{
			Rectangle::Show();
		}
};

int main(void)
{
	Rectangle rec(4,3);
	rec.Show();

	Square sqr(7);
	sqr.Show();

	return 0;
}
