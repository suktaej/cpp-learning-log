#include<iostream>

template<typename T,int len>
class SimpleArray
{
	private:
		T arr[len];
	public:
		T& operator[](int idx){return arr[idx];}
		SimpleArray<T,len>& operator=(const SimpleArray<T,len>& ref)
		{
			for(int i=0;i<len;i++)
				arr[i]=ref.arr[i];
		}
};

int main(void)
{
	SimpleArray<int,5> i5arr1;
	for(int i=0;i<5;i++)
		i5arr1[i]=i*10;

	SimpleArray<int,5> i5arr2;
	i5arr2=i5arr1;

	for(int i=0;i<5;i++)
		std::cout<<i5arr2[i]<<",";
	std::cout<<std::endl;
}
