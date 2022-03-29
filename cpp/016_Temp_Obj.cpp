#include<iostream>

class Sample
{
	private:
		int num;
	public:
		Sample(int n):num(n){std::cout<<"called const:"<<this<<std::endl;}
		Sample(const Sample& copy):num(copy.num){std::cout<<"called copy const:"<<this<<std::endl;}
		~Sample(){std::cout<<"called dest:"<<this<<std::endl;}
};

Sample SampleFunObj(Sample ob)
{
	std::cout<<"para addr:"<<&ob<<std::endl;
	return ob;
}

int main(void)
{
	Sample obj(10);
	SampleFunObj(obj);

	std::cout<<std::endl;

	Sample tempRef=SampleFunObj(obj);
	std::cout<<"Return obj:"<<&tempRef<<std::endl;
	return 0;
}
