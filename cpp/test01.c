#include <stdio.h>

void Fun(char *myname)
{
	char *name;
	name=myname;

	printf("%s\t%d\n",name,*name);
	printf("%d\n",*myname);

	return;
}

int main(void)
{
	char str[10]="asdfzxcv";
	char *pstr="qwer";
	Fun(str);
	Fun(pstr);

	return 0;
}
