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
	Person *parr[3];
	
	char n1[10]="kim";
	char n2[10]="Lee";
	char n3[10]="Park";

	parr[0]=new Person(n1,10);
	parr[1]=new Person(n2,20);
	parr[2]=new Person(n3,30);

	for(int i=0;i<3;i++) {parr[i]->ShowPerson();}
	for(int i=0;i<3;i++) {delete parr[i];}

	return 0;
}
