#include<iostream>
#include<cstdlib>

class BCIArray
{
	private:
		int *arr;
		int arrlen;
	public:
		BCIArray(int len):arrlen(len)
		{
			arr=new int[len];
		}
		int& operator[] (int idx)
		{
			if(idx<0||idx>=arrlen)
			{
				std::cout<<"error"<<std::endl;
				exit(1);
			}
			return arr[idx];
		}
		~BCIArray()
		{
			delete[] arr;
		}
};


int main(void)
{
	BCIArray arr(4);
	
	for(int i=0;i<4;i++)
		arr[i]=(i+1)*11;
	for(int i=0;i<5;i++)
		std::cout<<arr[i]<<std::endl;
	return 0;
}
