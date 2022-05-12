#include<iostream>
#include<cstring>

template<typename T>
T max(T a,T b){return a>b?a:b;}
template<>
char* max(char* a,char* b){return strlen(a)>strlen(b)?a:b;}
template<>
const char* max(const char* a,const char*b){return strcmp(a,b)>0?a:b;}

int main(void)
{
	std::cout<<max("sim","best")<<std::endl;
	
	char str1[]="sim";
	char str2[]="best";
	std::cout<<max(str1,str2)<<std::endl;

	return 0;
}

