#include<iostream>
#include<cstring>

template<typename T>
class Point
{
	private:
		T xpos,ypos;
	public:
		Point(T x=0,T y=0);
		void Show() const;
};

template<typename T>
class SimpleDataWrapper
{
	private:
		T mdata;
	public:
		SimpleDataWrapper(T data):mdata(data){}
		void Show(){std::cout<<"Data:"<<mdata<<std::endl;}
};

template<>
class SimpleDataWrapper<char*>
{
	private:
		char* mdata;
	public:
		SimpleDataWrapper(char* data)
		{
			mdata=new char[strlen(data)+1];
			strcpy(mdata,data);
		}
		void Show(){std::cout<<"String:"<<mdata<<std::endl;}
		~SimpleDataWrapper(){delete[] mdata;}
};

template<>
class SimpleDataWrapper<Point<int>>
{
	private:
		Point<int> mdata;
	public:
		SimpleDataWrapper(int x,int y):mdata(x,y){}
		void Show(){mdata.Show();}
};

template<typename T>
Point<T>::Point(T x,T y):xpos(x),ypos(y){}

template<typename T>
void Point<T>::Show() const {std::cout<<"Point("<<xpos<<","<<ypos<<")"<<std::endl;}

int main(void){

	SimpleDataWrapper<int> ivar(100);
	ivar.Show();
	SimpleDataWrapper<char*> cpvar("Class Template Spec");
	cpvar.Show();
	SimpleDataWrapper<Point<int>> pvar(1,2);
	pvar.Show();

	return 0;
}
