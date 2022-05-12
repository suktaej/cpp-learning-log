#include<iostream>

class Point
{
	private:
		int xpos,ypos;
	public:
		Point(int x=0,int y=0):xpos(x),ypos(y){}
		void SetPos(int x,int y)
		{
			xpos=x;
			ypos=y;
		}
		void Show() const {std::cout<<xpos<<","<<ypos<<std::endl;}
};

template<typename T>
class SmartPtr
{
	private:
		T* posptr;
	public:
		SmartPtr(T* ptr);
		T& operator*() const{return *posptr;}
		T* operator->() const{return posptr;}
		~SmartPtr(){delete posptr;}
};

template<typename T>
SmartPtr<T>::SmartPtr(T* ptr):posptr(ptr){}

int main(void)
{
	SmartPtr<Point> sptr1(new Point(1,2));
	SmartPtr<Point> sptr2(new Point(3,4));

	sptr1->Show();
	sptr2->Show();
	
	sptr1->SetPos(10,20);
	sptr2->SetPos(30,40);
	sptr1->Show();
	sptr2->Show();

	return 0;
}
