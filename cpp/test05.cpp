#include<iostream>
#include<cstring>

class AAA
{
	private:
		char* str;
	public:
		AAA(char* inp)
		{
			str=new char[strlen(inp)+1];
			strcpy(str,inp);
		}
		~AAA()
		{
			if(str!=NULL)
				delete[] str;
		}
};

AAA* a[10];

int main(void)
{
	char temp1[8];
	std::cin>>temp1;

	a[0] = new AAA(temp1);
	delete[] a[0];

	return 0;
}
