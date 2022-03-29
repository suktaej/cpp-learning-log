#include <iostream>
#include <cstring>

class Person{

	private:
		char *name;
		int age;
	public:
		Person(char *input_name,int input_num)
		{
			int len=strlen(input_name)+1;
			name=new char[len];
			strcpy(name,input_name);
			age=input_num;
			std::cout<<"called Person(parameter)"<<std::endl;
		}
		
		Person()
		{
			name=NULL;
			age=0;
			std::cout<<"called Person()"<<std::endl;
		}

		Person(const Person& copy):age(copy.age)
		{
			name=new char[strlen(copy.name)+1];
			strcpy(name,copy.name);
		}

		void SetPerson(char *input_name,int input_num)
		{
			name=input_name;
			age=input_num;
		}

		void ShowPerson() const
		{
			std::cout<<"name:"<<name<<std::endl;
			std::cout<<"age:"<<age<<std::endl;
		}

		~Person()
		{
			delete []name;
			std::cout<<"called Destructor"<<std::endl;
		}
};

int main(void)
{
	Person parr[3];

	char *pstr;
	int len;

	char n1[10]="Kim";
	char n2[10]="Lee";
	char n3[10]="Park";

	len=strlen(n1)+1;
	pstr=new char[len];
	strcpy(pstr,n1);
	
	parr[0].SetPerson(pstr,10);
	parr[1].SetPerson(pstr,20);
	parr[2].SetPerson(pstr,30);
/*
	parr[0].SetPerson(n1,10);
	parr[1].SetPerson(n2,20);
	parr[2].SetPerson(n3,30);
*/
	for(int i=0;i<3;i++) {parr[i].ShowPerson();}

	return 0;
}
