#ifndef __POINT_H__
#define __POINT_H__

class Point{
	private:
		int xpos,ypos;
	public:
		Point(const int &x,const int &y);
		int GetX() const;
		int GetY() const;
		bool SetX(int x);
		bool SetY(int y);
};

#endif
