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
		
		void SetPerson(char *input_name,int input_num)
		{
			name=input_name;
//			strcpy(name,input_name);
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

	int age=99;
	int len;

	char n1[20]="Kimkim";
	char n2[20]="Leelee";
	char n3[20]="Parkpark";

	len=strlen(n1)+1;
	pstr=new char[len];
	strcpy(pstr,n1);
	
	parr[0].SetPerson(pstr,age);
	parr[1].SetPerson(n2,age);
	parr[2].SetPerson(n3,age);

	for(int i=0;i<3;i++) {parr[i].ShowPerson();}

	return 0;
}
