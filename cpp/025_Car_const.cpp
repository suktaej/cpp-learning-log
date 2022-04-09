#include<iostream>
#include<cstring>

class Car
{
	private:
		int gasoline;
	public:
		Car(int num):gasoline(num){}
		~Car(){}

		int GetGas()
		{
			return gasoline;
		}
};

class Hybrid_Car: public Car
{
	private:
		int electrnic;
	public:
		Hybrid_Car(int num1,int num2):Car(num1),electrnic(num2){}
		~Hybrid_Car(){}

		int GetEle()
		{
			return electrnic;
		}
};

class Water_Car: public Hybrid_Car
{
	private:
		int water;
	public:
		Water_Car(int num1,int num2, int num3):Hybrid_Car(num1,num2),water(num3){}
		~Water_Car(){}

		void GetWtr()
		{
			std::cout<<"gas:"<<GetGas()<<std::endl;
			std::cout<<"ele:"<<GetEle()<<std::endl;
			std::cout<<"wtr:"<<water<<std::endl;
		}
};

int main(void)
{
	Water_Car car1(10,20,30);
	car1.GetWtr();

	return 0;
}
