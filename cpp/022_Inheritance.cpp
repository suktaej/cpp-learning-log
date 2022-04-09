#include<iostream>
#include<cstring>

class Person
{
	private:
		int age;
		char name[100];
	public:
		Person(int myage,char *myname):age(myage)
		{
			strcpy(name,myname);
		}
		void ShowName() const
		{
			std::cout<<"name:"<<name<<std::endl;
		}
		void ShowAge() const
		{
			std::cout<<"age:"<<age<<std::endl;
		}
};

class Uni_Student:public Person
{
	private:
		char major[50];
	public:
		Uni_Student(int myage,char *myname,char *mymajor):Person(myage,myname)
		{
			strcpy(major,mymajor);
		}
		void Show_you() const
		{
			ShowName();
			ShowAge();
			std::cout<<"major:"<<major<<std::endl;
		}
};

int main(void)
{
	Uni_Student std1(18,"Lee","COM");
	std1.Show_you();

	Uni_Student std2(21,"Kim","HIS");
	std2.Show_you();

	return 0;
}
