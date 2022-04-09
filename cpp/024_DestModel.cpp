#include<iostream>
#include<cstring>

class Person
{
	private:
		char *name;
	public:
		Person(char *str)
		{
			name=new char[strlen(str)+1];
			strcpy(name,str);
		}
		~Person()
		{
			delete[] name;
		}

		void Show() const
		{
			std::cout<<"name is:"<<name<<std::endl;
		}
};

class Student: public Person
{
	private:
		char *major;
	public:
		Student(char *str1, char *str2):Person(str1)
		{
			major=new char[strlen(str2)+1];
			strcpy(major,str2);
		}
		~Student()
		{
			delete[] major;
		}

		void Show() const
		{
			Person::Show();
			std::cout<<"major is:"<<major<<std::endl;
		}
};

int main(void)
{
	Student st1("Kim","Math");
	st1.Show();

	Student st2("Lee","Eng");
	st2.Show();

	return 0;
}
