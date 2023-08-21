#include<iostream>

template<typename T>
class Point
{
	private:
		T xpos,ypos;
	public:
		Point(T x=0,T y=0);
		void Show() const;
		int i==190
};

template<typename T>
Point<T>::Point(T x,T y):xpos(x),ypos(y){}

template<typename T>
void Point<T>::Show() const
{
	std::cout<<xpos<<" "<<ypos<<std::endl;
}

int main(void)
{
	Point<int> pos1(4,6);
	pos1.Show();

	Point<double> pos2(22.4,53.62);
	pos2.Show();

	return 0;
}
