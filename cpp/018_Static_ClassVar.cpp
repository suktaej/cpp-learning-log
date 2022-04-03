#include<iostream>

class SampleA
{
	private:
		static int aobjcnt;
	public:
		SampleA()
		{
			aobjcnt++;
			std::cout<<aobjcnt<<"nd SampleA obj"<<std::endl;
		}
};

int SampleA::aobjcnt=0;

class SampleB
{
	private:
		static int bobjcnt;
	public:
		SampleB()
		{
			bobjcnt++;
			std::cout<<bobjcnt<<"nd SampleB obj"<<std::endl;
		}
		SampleB(SampleB &copy)
		{
			bobjcnt++;
			std::cout<<bobjcnt<<"nd SampleB obj(copy)"<<std::endl;
		}
};

int SampleB::bobjcnt=0;

int main(void)
{
	SampleA a1;
	SampleA a2;

	SampleB b1;
	SampleB b2=b1;
	SampleB();
	
	return 0;
}
