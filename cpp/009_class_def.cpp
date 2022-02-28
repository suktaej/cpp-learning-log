#include<iostream>

class Point{
	private:
		int xpos,ypos;
	public:
		void Init(int x,int y);
		void Show() const;
};

class Ring{
	private:
		Point poi;
		int rad;
	public:
		void Init(int x,int y,int z);
		void Show() const;
};

class Circle{
	private:
		Ring r1,r2;
	public:
		void Init(int x1,int y1,int z1,int x2,int y2,int z2);
		void Show() const;
};

void Point::Init(int x,int y)
{
	xpos=x;
	ypos=y;
}

void Point::Show(void) const
{
	std::cout<<'('<<xpos<<','<<ypos<<')'<<std::endl;
}

void Ring::Init(int x,int y,int z)
{
	poi.Init(x,y);
	rad=z;
}

void Ring::Show(void) const
{
	std::cout<<"radius:"<<rad<<std::endl;
	poi.Show();
}

void Circle::Init(int x1,int y1,int z1,int x2,int y2,int z2)
{
	r1.Init(x1,y1,z1);
	r2.Init(x2,y2,z2);
}

void Circle::Show(void) const
{
	std::cout<<"inner:";
	r1.Show();
	std::cout<<"Outter:";
	r2.Show();
}

int main(void)
{
	Circle ring;
	ring.Init(1,1,2,2,2,9);
	ring.Show();

	return 0;
}
