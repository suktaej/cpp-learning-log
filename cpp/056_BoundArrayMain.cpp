#include<iostream>
#include"056_ArrayTemplate.h"
#include"056_Point.h"

int main(void)
{
	BoundCheckArr<int> iarr(5);
	for(int i=0;i<5;i++)
		iarr[i]=(i+1)*11;
	for(int i=0;i<5;i++)
		std::cout<<iarr[i]<<std::endl;

	BoundCheckArr<Point> parr(3);
	parr[0]=Point(10,15);
	parr[1]=Point(20,25);
	parr[2]=Point(30,35);
	for(int i=0;i<parr.GetArrLen();i++)
		std::cout<<parr[i];

	typedef Point* POINT_PTR;
	BoundCheckArr<POINT_PTR> aarr(3);
	aarr[0]=new Point(11,21);
	aarr[1]=new Point(31,41);
	aarr[2]=new Point(51,61);
	for(int i=0;i<aarr.GetArrLen();i++)
		std::cout<<*(aarr[i]);

	delete aarr[0];
	delete aarr[1];
	delete aarr[2];

	return 0;
}
