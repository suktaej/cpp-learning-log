#include<iostream>
#include<cstring>

class Gun
{
	private:
		int bullet;
	public:
		Gun(int b_num):bullet(b_num){}
		void Shut()
		{
			std::cout<<"bang"<<std::endl;
			bullet--;
		}
};

class Police
{
	private:
		int handcuffs;
		Gun *pistol;
	public:
		Police(int b_num,int b_cuff):handcuffs(b_cuff)
		{
			if(b_num>0)
				pistol=new Gun(b_num);
			else
				pistol=NULL;
		}

		void Puthandcuff()
		{
			std::cout<<"snap"<<std::endl;
			handcuffs--;
		}

		void Shut()
		{
			if(pistol==NULL)
				std::cout<<"hut bang"<<std::endl;
			else
				pistol->Shut();
		}
};

int main(void)
{
	Police pman1(5,3);
	pman1.Shut();
	pman1.Puthandcuff();

	Police pman2(0,3);
	pman2.Shut();
	pman2.Puthandcuff();

	return 0;
}
