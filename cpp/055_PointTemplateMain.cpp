#include<iostream>
#include"055_PointTemplate.h"
#include"055_PointTemplate.cpp"

int main(void)
{
	Point<int> pos1(4,6);
	pos1.Show();

	Point<double> pos2(12.32,58.33);
	pos2.Show();

	Point<char> pos3('A','f');
	pos3.Show();

	return 0;
}
