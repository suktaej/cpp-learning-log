#include<iostream>

void A_Fun(int &rPara);
void B_Fun(int *pPara);
void C_Fun(int &a, int &b);
void Print_Fun(void);

int main(void){

	Print_Fun();
	return 0;
}

void Print_Fun(void){
	
	int *ninit1 = new int;
	int *ninit2 = new int(10);
	int sinit1(15);
	
	int &ref = sinit1;
	int *ptrData = &sinit1;

	*ninit1 = 5;

	std::cout<<"N_ini1:"<<*ninit1<<std::endl; //5
	std::cout<<"N_ini2:"<<*ninit2<<std::endl; //10

	ref=20;
	std::cout<<"S_ini1:"<<sinit1<<std::endl; //20

	*ptrData = 30;
	std::cout<<"S_ini1:"<<sinit1<<std::endl; //30

	A_Fun(sinit1);
	std::cout<<"S_ini1:"<<sinit1<<std::endl; //100
	
	B_Fun(&sinit1);
	std::cout<<"S_ini1:"<<sinit1<<std::endl; //55
	
	B_Fun(ninit1);
	std::cout<<"N_ini1:"<<*ninit1<<std::endl;

	C_Fun(sinit1,*ninit1);
	std::cout<<"S1,N1:"<<sinit1<<','<<*ninit2<<std::endl;

	delete ninit1;
	delete ninit2;
}


void A_Fun(int &rPara){

	rPara=100;
}

void B_Fun(int *pPara){

	int tmp(55);

	//std::cout<<*pPara<<std::endl;
	*pPara=tmp;
}

void C_Fun(int &a, int &b){

	int tmp = a;
	a = b;
	b = tmp;
}

