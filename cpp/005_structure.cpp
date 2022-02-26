#include<iostream>

struct Point
{
	int xpos;
	int ypos;

	void MovePos(int x, int y);
	void AddPoint(const Point &pos);
	void ShowPosition();
};

int main(void)
{
	Point pos1={12,4};		//c type declare 'struct Point pos1' or using typedef 
	Point pos2={20,30};

	pos1.MovePos(-7,10);
	pos1.ShowPosition();

	pos1.AddPoint(pos2);
	pos1.ShowPosition();

	return 0;
}

inline void Point::MovePos(int x, int y)		//cpp type(c type can`t use function in structure)
{
	xpos+=x;
	ypos+=y;
}

inline void Point::AddPoint(const Point &pos)
{
	xpos+=pos.xpos;
	ypos+=pos.ypos;
}

inline void Point::ShowPosition()
{
	std::cout<<xpos<<'.'<<ypos<<std::endl;
}
