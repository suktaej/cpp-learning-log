#include<iostream>

class Date
{
	private:
		int year_;
		int month_;
		int day_;
	public:
		void SetDate(int year,int month, int date);
		void AddDay(int inc);
		void AddMonth(int inc);
		void AddYear(int inc);

		void ShowDate();
};

void Date::SetDate(int year,int month,int date)
{

}

void Date::ShowDate(void)
{
	std::cout<<year_<<"/"<<month_<<"/"<<day_<<std::endl;
}
