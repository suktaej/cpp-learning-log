#include<iostream>
#include<cstdlib>

class BoundCheckIntArray
{
	private:
		int *arr;
		int arrlen;
		BoundCheckIntArray(const BoundCheckIntArray& ref){}
		BoundCheckIntArray& operator=(const BoundCheckIntArray& ref){}
	public:
		BoundCheckIntArray(int len):arrlen(len)
		{
			arr=new int[len];
		}
		int& operator[] (int idx)
		{
			if(idx<0||idx>=arrlen)
				exit(1);
			return arr[idx];
		}
		int& operator[] (int idx) const
		{
			if(idx<0||idx>=arrlen)
				exit(1);
			return arr[idx];
		}
//		int GetArrLen() const{return arrlen;}
		~BoundCheckIntArray(){delete[] arr;}
};

typedef BoundCheckIntArray* BoundCheckIntArrayPtr;

class BoundCheckInt2DArray 
{
	private:
		BoundCheckIntArray **arr;
		int arrlen;
		BoundCheckInt2DArray(const BoundCheckInt2DArray &ref){}
		BoundCheckInt2DArray& operator=(const BoundCheckInt2DArray &ref){}
	public:
		BoundCheckInt2DArray(int col,int row):arrlen(col)
		{
			arr=new BoundCheckIntArrayPtr[col];
			for(int i=0;i<col;i++)
				arr[i]=new BoundCheckIntArray(row);
		}
		BoundCheckIntArray& operator[](int idx)
		{
			if(idx<0||idx>=arrlen)
				exit(1);
			return *(arr[idx]);
		}
		~BoundCheckInt2DArray(){delete[] arr;}
};

int main(void)
{
	BoundCheckInt2DArray arr2d1(3,4);

	for(int n=0;n<3;n++)
		for(int m=0;m<4;m++)
			arr2d1[n][m]=n+m;

	for(int n=0;n<3;n++)
	{
		for(int m=0;m<4;m++)
			std::cout<<arr2d1[n][m]<<' ';
		std::cout<<std::endl;
	}
	return 0;
}
