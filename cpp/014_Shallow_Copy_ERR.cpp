#include <iostream>
#include <cstring>

class Person
{
	private:
		char* name;
		int age;
	public:
		Person(const char* inp_name,int inp_age)
		{
			int len=strlen(inp_name)+1;
			name=new char[len];
			strcpy(name,inp_name);
			age=inp_age;
		}
//insert deep copy
		
		Person(const Person& copy): age(copy.age)
		{
			name=new char[strlen(copy.name)+1];
			strcpy(name,copy.name);
		}

		void Show() const
		{
			std::cout<<"name:"<<name<<std::endl;
			std::cout<<"age:"<<age<<std::endl;
		}

		~Person()
		{
			delete []name;
			std::cout<<"called destructor"<<std::endl;
		}
};

int main(void)
{
	Person man1("Kim",10);
	Person man2=man1;

	man1.Show();
	man2.Show();

	return 0;
}
