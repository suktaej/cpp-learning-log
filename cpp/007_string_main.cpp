#include"007_string.h"

int main(void)
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love you");
	pnt.ShowString();

	return 0;
}
