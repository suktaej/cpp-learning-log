#include<stdio.h>

int main(void)
{
	int num=10,cnum=100;
	const int* cp_num=&num;
	int* const pc_num=&num;

	cp_num=&cnum;
	*cp_num=50;

	pc_num=&cnum;
	*pc_num=50;

	return 0;
}
