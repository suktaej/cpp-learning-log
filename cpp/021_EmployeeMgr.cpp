#include<iostream>
#include<cstring>

using namespace std;

class PermanentWorker
{
	private:
		char name[100];
		int salary;
	public:
		PermanentWorker(const char *name,int money):salary(money)
		{
			strcpy(this->name,name);
		}
		int Getpay() const
		{
			return salary;
		}
		void Show() const
		{
			cout<<"name:"<<name<<endl;
			cout<<"salary:"<<Getpay()<<endl;
		}
};

class EmployeeHandler
{
	private:
		PermanentWorker* emplist[100];
		int empnum;
	public:
		EmployeeHandler():empnum(0){}
		void AddEmp(PermanentWorker* emp)
		{
			emplist[empnum++]=emp;
		}
		void ShowSalary() const
		{
			for(int i=0;i<empnum;i++)
				emplist[i]->Show();
		}
		void ShowTotal() const
		{
			int sum=0;
			for(int i=0;i<empnum;i++)
				sum+=emplist[i]->Getpay();
			cout<<"salary sum:"<<sum<<endl;
		}
		~EmployeeHandler()
		{
			for(int i=0;i<empnum;i++)
				delete emplist[i];
		}
};

int main(void)
{
	EmployeeHandler handler;

	handler.AddEmp(new PermanentWorker("kim",1000));
	handler.AddEmp(new PermanentWorker("lee",1500));
	handler.AddEmp(new PermanentWorker("Park",2000));

	handler.ShowSalary();
	handler.ShowTotal();

	return 0;
}
