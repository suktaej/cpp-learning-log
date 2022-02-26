#include<iostream>
#include<string.h>
#include<stdlib.h>

typedef struct _Point
{
	int xpos;
	int ypos;
}Point;

Point& PntAdd(const Point &pt1,const Point &pt2)
{
	Point apt;
	Point *ppt = new Point;

	apt.xpos=pt1.xpos+pt2.xpos;
	apt.ypos=pt1.ypos+pt2.ypos;
	
	ppt->xpos=pt1.xpos+pt2.xpos;
	ppt->ypos=pt1.ypos+pt2.ypos;

	std::cout<<apt.xpos<<','<<apt.ypos<<std::endl;

	return *ppt;
}

char* MakeStrAdd(int len)
{
	//char *str=(char*)malloc(sizeof(char)*len);
	char* str=new char[len];
	return str;
}

void RefStr(void)
{
	int *ptr=new int;
	int &ref=*ptr;
	ref=20;
	std::cout<<ref<<std::endl;
	delete ptr;
}

int main(void)
{
	using std::cout; using std::endl;

	char *str=MakeStrAdd(20);
	strcpy(str,"hello world!");
	cout<<str<<endl;
	//free(str);
	delete []str;
	RefStr();

	Point *mpt1 = new Point;
	mpt1->xpos=1;
	mpt1->ypos=9;

	Point *mpt2 = new Point;
	mpt2->xpos=10;
	mpt2->ypos=90;

	Point &rpt = PntAdd(*mpt1,*mpt2); 
	cout<<rpt.xpos<<','<<rpt.ypos<<endl;

	delete mpt1;
	delete mpt2;
	delete &rpt;
	return 0;
}
