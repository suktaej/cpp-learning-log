#include<iostream>
#include<cstring>

class Friend
{
	private:
		char *name;
		int age;
	public:
		Friend(char *name,int age):age(age)
		{
			this->name = new char[strlen(name)+1];
			strcpy(this->name,name);
		}
		~Friend()
		{
			delete[] name;
		}

		void Show()
		{
			std::cout<<"name:"<<name<<std::endl;
			std::cout<<"age:"<<age<<std::endl;
		}
};

class Friend_Detail:public Friend
{
	private:
		char *addr;
		char *phone;
	public:
		Friend_Detail(char *name,char *addr,char *phone,int age):Friend(name,age)
		{
			this->addr=new char[strlen(addr)+1];
			this->phone=new char[strlen(phone)+1];
			strcpy(this->addr,addr);
			strcpy(this->phone,phone);
		}
		~Friend_Detail()
		{
			delete[] addr;
			delete[] phone;
		}

		void Show()
		{
			Friend::Show();
			std::cout<<"addr:"<<addr<<std::endl;
			std::cout<<"phone:"<<phone<<std::endl;
		}
};

int main(void)
{
	Friend_Detail f1("Kim","CityA","010-4024-5823",42);
	Friend_Detail f2("Lee","CityB","010-4902-5555",18);

	f1.Show();
	f2.Show();
	
	return 0;
}
