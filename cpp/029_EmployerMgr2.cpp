#include<iostream>
#include<cstring>

using namespace std;

class Employee
{
	private:
		char name[30];
	public:
		Employee(char* name)
		{
			strcpy(this->name,name);
		}
		void ShowName() const
		{
			std::cout<<"name:"<<name<<std::endl;
		}
		virtual int Getpay() const
		{
			return 0;
		}
		virtual void Show() const {}
};

class PermanentWorker: public Employee
{
	private:
		int salary;
	public:
		PermanentWorker(char *name,int money):Employee(name),salary(money){}
		
		int Getpay() const
		{
			return salary;
		}
		void Show() const
		{
			ShowName();
			cout<<"salary:"<<Getpay()<<endl;
		}
};

class TempraryWorker: public Employee
{
	private:
		int worktime;
		int pph;
	public:
		TempraryWorker(char* name,int pay):Employee(name),worktime(0),pph(pay){}
		
		void AddWorktime(int time)
		{
			worktime+=time;
		}
		int Getpay() const
		{
			return worktime*pph;
		}
		void Show() const
		{
			ShowName();
			std::cout<<"salary:"<<Getpay()<<std::endl;
		}
};

class SalesWorker: public PermanentWorker
{
	private:
		int sale_result;
		double bonus_ratio;
	public:
		SalesWorker(char* name,int sale, double rate):PermanentWorker(name,sale),sale_result(0),bonus_ratio(rate){}

		void AddSaleResult(int value)
		{
			sale_result+=value;
		}
		int Getpay() const
		{
			return PermanentWorker::Getpay()+(int)(sale_result*bonus_ratio);
		}
		void Show() const
		{
			ShowName();
			std::cout<<"salary:"<<Getpay()<<std::endl;
		}
};

class EmployeeHandler
{
	private:
		Employee* emplist[10];
		int empnum;
	public:
		EmployeeHandler():empnum(0){}

		void AddEmp(Employee* emp)
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
	
	TempraryWorker* arbeit=new TempraryWorker("Jeong",500);
	arbeit->AddWorktime(6);
	handler.AddEmp(arbeit);

	SalesWorker *seller=new SalesWorker("Choi",3000,0.1);
	seller->AddSaleResult(10000);
	handler.AddEmp(seller);

	handler.ShowSalary();
	handler.ShowTotal();

//	std::cout<<seller.Getpay()<<std::endl;
//	seller.Show();
//	std::cout<<seller.PermanentWorker::Getpay()<<std::endl;
//	seller.PermanentWorker::Show();

	return 0;
}
