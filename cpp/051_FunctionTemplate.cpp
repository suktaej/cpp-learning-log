#include<iostream>

template<typename d1>
void swap(d1 &num1, d1 &num2)
{
	d1 temp=num1;
	num1=num2;
	num2=temp;
}
template<typename d2>
d2 SumArray(d2 arr[],int len)
{
	d2 sum=(d2)0;
	for(int i=0;i<len;i++)
		sum+=arr[i];
	return sum;
}

class Point
{
	private:
		int xpos,ypos;
	public:
		Point(int x=0,int y=0):xpos(x),ypos(y){}
		void Show() const{std::cout<<xpos<<" "<<ypos<<std::endl;}
};

int main(void)
{
	Point pos1(10,20);
	Point pos2(3,7);
	swap(pos1,pos2);
	pos1.Show();
	pos2.Show();

	int arr1[]={1,2,3};
	std::cout<<SumArray(arr1,sizeof(arr1)/sizeof(int))<<std::endl;
	double arr2[]={1.2,3.4,5.6};
	std::cout<<SumArray(arr2,sizeof(arr2)/sizeof(double))<<std::endl;

	return 0;
}
