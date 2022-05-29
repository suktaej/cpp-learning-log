#include<iostream>

template<typename T=int,int len=5>
class SA
{
	private:
		T arr[len];
	public:
		T& operator[](int idx){return arr[idx];}
		SA<T,len>& operator=(const SA<T,len>& ref)
		{
			for(int i=0;i<len;i++)
				arr[i]=ref.arr[i];
		}
};

int main(void)
{
	SA<> arr;
	for(int i=0;i<5;i++)
	{	
		arr[i]=i+1;
		std::cout<<arr[i]<<" ";
	}

	std::cout<<std::endl;

//	SA<double,3> darr;
//	for(int i=0;i<3;i++)
//	{	
//		arr[i]=i+1.5;
//		std::cout<<arr[i]<<" ";
//	}
//		
//	std::cout<<std::endl;
	return 0;
}
