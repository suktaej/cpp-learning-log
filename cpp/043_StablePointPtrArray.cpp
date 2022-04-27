#include<iostream>
#include<cstdlib>

class Point
{
	private:
		int xpos,ypos;
	public:
		Point(int x=0,int y=0):xpos(x),ypos(y){}
		friend std::ostream& operator<<(std::ostream& os,const Point &pos);
		friend std::ostream& operator<<(std::ostream& os,const Point *pos);
};

std::ostream& operator<<(std::ostream &os,const Point &pos)
{
	os<<pos.xpos<<"\t"<<pos.ypos<<std::endl;
	return os;
}

std::ostream& operator<<(std::ostream &os,const Point *pos)
{
	os<<pos->xpos<<"\t"<<pos->ypos<<std::endl;
	return os;
}

typedef Point* Point_PTR;

class BCPPArray
{
	private:
		Point_PTR *arr;
		int arrlen;

		BCPPArray(const BCPPArray& ref){}
		BCPPArray& operator=(const BCPPArray &ref){}
	public:
		BCPPArray(int len):arrlen(len)
		{
			arr=new Point_PTR[len];
		}
		Point_PTR& operator[](int idx)
		{
			if(idx<0||idx>=arrlen)
			{
				std::cout<<"Array index out of bound exception"<<std::endl;
				exit(1);
			}
			return arr[idx];
		}
		Point_PTR& operator[](int idx) const
		{
			if(idx<0||idx>=arrlen)
			{
				std::cout<<"Array index out of bound exception"<<std::endl;
				exit(1);
			}
			return arr[idx];
		}
		int GetArrlen() const {return arrlen;}
		~BCPPArray() {delete[] arr;}
};

int main(void)
{
	BCPPArray arr(3);

	arr[0]=new Point(1,2);
	arr[1]=new Point(3,4);
	arr[2]=new Point(5,6);

//	for(int i=0;i<arr.GetArrlen();i++)
//		std::cout<<*(arr[i]);
	for(int i=0;i<arr.GetArrlen();i++)
		std::cout<<arr[i];

	delete arr[0];
	delete arr[1];
	delete arr[2];

	return 0;
}
