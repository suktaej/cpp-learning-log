#include<iostream>

class Point
{
	private:
		int xpos, ypos;
	public:
		Point(int inpx,int inpy):xpos(inpx),ypos(inpy){}

		void Show() const
		{
			std::cout<<"x:"<<xpos<<"\ty:"<<ypos<<std::endl;
		}
		Point& operator+=(const Point &ref)
		{
			xpos+=ref.xpos;
			ypos+=ref.ypos;

			return *this;
		}

		Point& operator++()
		{
			xpos+=1;
			ypos+=1;
			return *this;
		}

		const Point operator++(int)
		{
			const Point reobj(xpos,ypos);
			xpos+=1;
			ypos+=1;
			return reobj;
		}

	friend Point operator+(const Point &pos1,const Point &pos2);
	friend Point operator-(const Point &pos1,const Point &pos2);
	friend bool operator==(const Point&,const Point&);
	friend bool operator!=(const Point&,const Point&);
	friend Point& operator--(Point&);
	friend const Point operator--(Point&,int);
};

Point operator+(const Point &pos1,const Point &pos2)
{
	Point pos(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
	return pos;
}

Point operator-(const Point &pos1,const Point &pos2)
{
	Point pos(pos1.xpos-pos2.xpos,pos1.ypos-pos2.ypos);
	return pos;
}

bool operator==(const Point &pos1,const Point &pos2)
{
	if(pos1.xpos==pos2.xpos && pos1.ypos==pos2.ypos)
		return true;
	else
		return false;
}

bool operator!=(const Point& pos1,const Point& pos2)
{
	return !(pos1==pos2);
}

Point& operator--(Point& ref)
{
	ref.xpos-=1;
	ref.ypos-=1;
	return ref;
}

const Point operator--(Point& ref,int)
{
	const Point reobj(ref.xpos,ref.ypos);
	ref.xpos-=1;
	ref.ypos-=1;
	return reobj;
}

int main(void)
{
	Point pos1(30,60);
	Point pos2(3,6);
	Point pos3=pos1+pos2;
	Point pos4=pos1-pos2;
	
	pos1.Show();
	pos2.Show();
	pos3.Show();
	pos4.Show();

	(pos1+=pos2).Show();
	
	if(pos1!=pos2)
		std::cout<<"not equal"<<std::endl;
	else
		std::cout<<"equal"<<std::endl;

	return 0;
}
