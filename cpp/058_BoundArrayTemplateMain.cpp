#include<iostream>
#include"058_PointTemplate.h"
#include"058_ArrayTemplate.h"

int main(void)
{
	BoundCheackArray<Point<int>> oarr(3);
	oarr[0]=Point<int>(1,2);
	oarr[1]=Point<int>(10,20);
	oarr[2]=Point<int>(100,200);

	for(int i=0;i<oarr.GetArrLen();i++)
		oarr[i].Show();

	typedef Point<int>* PTR_POINT;
	BoundCheackArray<PTR_POINT> parr(3);
	parr[0]=new Point<int>(3,4);
	parr[1]=new Point<int>(30,40);
	parr[2]=new Point<int>(300,400);

	for(int i=0;i<parr.GetArrLen();i++)
		parr[i]->Show();

	for(int i=0;i<parr.GetArrLen();i++)
		delete parr[i];

	return 0;
}
