#ifndef __CAR_TRUCK_
#define __CAR_TRUCK_
#include<iostream>

class Car
{
	private:
		int fuel;
	public:
		Car(int input):fuel(input){}
		void Show(){std::cout<<"fuel:"<<fuel<<std::endl;}
};

class Truck:public Car
{
	private:
		int freight;
	public:
		Truck(int input,int load):Car(input),freight(load){}
		void Show()
		{
			Car::Show();
			std::cout<<"freight:"<<freight<<std::endl;
		}
};

#endif
