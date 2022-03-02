#include<iostream>
#include"009_rectangle.h"
#include"009_point.h"

int main(void)
{
	Rectangle rec(1,1,5,5);
	Rectangle *prec = new Rectangle(3,3,7,7);

	rec.Show();
	prec->Show();

	delete prec;
	return 0;
}

