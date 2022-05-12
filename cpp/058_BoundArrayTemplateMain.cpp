#include<iostream>
#include"058_PointTemplate.h"
#include"056_ArrayTemplate.h"

int main(void)
{
	BoundCheckArr<Point<int>> oarr1(3);
	oarr1[0]=Point<int>(1,2);
	oarr1[1]=Point<int>(10,20);
	oarr1[2]=Point<int>(100,200);

	for(int i=0;i<oarr1.GetArrLen();i++)
		oarr1[i].Show();

	typedef Point<int>* 
}
