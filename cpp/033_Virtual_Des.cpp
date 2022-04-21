#include<iostream>
#include<cstring>

class First
{
	private:
		char *str1;
	public:
		First(char* inp)
		{
			str1=new char[strlen(inp)+1];
			std::cout<<"First const"<<std::endl;
		}
		virtual ~First()
		{
			delete[] str1;
			std::cout<<"virtual first dest"<<std::endl;
		}

		virtual void Show() const
		{
			std::cout<<"A"<<std::endl;
		}
};

class Second:public First
{
	private:
		char* str2;
	public:
		Second(char* inp1,char* inp2):First(inp1)
		{
			str2=new char[strlen(inp2)+1];
			std::cout<<"Second const"<<std::endl;
		}
		~Second()
		{
			delete[] str2;
			std::cout<<"Second dest"<<std::endl;
		}

		void Show() const
		{
			std::cout<<"B"<<std::endl;
		}
};

class Third:public Second
{
	private:
		char* str3;
	public:
		Third(char* inp1,char* inp2,char* inp3):Second(inp1,inp2)
		{
			str3=new char[strlen(inp3)+1];
			std::cout<<"Third const"<<std::endl;
		}
		~Third()
		{
			delete[] str3;
			std::cout<<"Third dest"<<std::endl;
		}

		void Show() const
		{
			std::cout<<"C"<<std::endl;
		}
};

void Call_Vir(const First &par1)
{
	par1.Show();
}

int main(void)
{
	First *ptr=new Second("AAA","BBB");
	//delete ptr;

	std::cout<<std::endl;

	First *ptr2=new Third("CCC","DDD","EEE");
	//delete ptr2;

	std::cout<<std::endl;

	Second *ptr3=new Third("FFF","GGG","HHH");
	//delete ptr3;
	
	std::cout<<std::endl;

	First nonptr("ABC");
	Third nonptr2("DEF","GHI","JKL");

	Call_Vir(nonptr);
	Call_Vir(nonptr2);

	Call_Vir(*ptr);
	Call_Vir(*ptr3);

	std::cout<<"--------------"<<std::endl;

	delete ptr;
	delete ptr2;
	delete ptr3;

	return 0;
}
