#include"006_cal_class.h"

int main(void)
{
	using std::cout; using std::endl;

	Calculator cal;
	cal.Init();
	cout<<"10+15="<<cal.Add(10,15)<<endl;
	cout<<"15-5="<<cal.Min(15,5)<<endl;
	cout<<"5*4="<<cal.Mul(5,4)<<endl;
	cout<<"10/2="<<cal.Div(10,2)<<endl;
	cal.ShowOpCount();
	return 0;
}
