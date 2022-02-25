#include<iostream>
#include<string.h>
#include<stdlib.h>

char* MakeStrAdd(int len)
{
	//char *str=(char*)malloc(sizeof(char)*len);
	char* str=new char[len];
	return str;
}

void RefStr(void)
{
	int *ptr=new int;
	int &ref=*ptr;
	ref=20;
	std::cout<<ref<<std::endl;
	delete ptr;
}

int main(void)
{
	using std::cout; using std::endl;

	char *str=MakeStrAdd(20);
	strcpy(str,"hello world!");
	cout<<str<<endl;
	//free(str);
	delete []str;
	RefStr();

	return 0;
}
