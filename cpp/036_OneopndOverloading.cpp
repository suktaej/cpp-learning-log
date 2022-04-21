#include<iostream>

class Point
{
	private:
		int xpos,ypos;
	public:
		Point(int inpx,int inpy):xpos(inpx),ypos(inpy){}

		Point operator-()
		{
			Point pos(-xpos,-ypos);
			return pos;
		}

		void Show() const
		{
			std::cout<<"x:"<<xpos<<"\ty:"<<ypos<<std::endl;
		}
};

int main(void)
{
	Point p1(10,20);
	Point p2(-1,-2);
	Point p3=-p1;

	p1.Show();
	p2.Show();
	p3.Show();
	(-p1).Show();

	return 0;
}
