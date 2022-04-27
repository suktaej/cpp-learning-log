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
		int Empty_bullet()
		{
			return bullet;
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
		Police(const Police &ref):handcuffs(ref.handcuffs)
		{
			pistol=new Gun(*(ref.pistol));
		}
		Police& operator=(const Police &ref)
		{
			if(pistol!=NULL)
				delete pistol;

			handcuffs=ref.handcuffs;
			pistol=new Gun(*(ref.pistol));

			return *this;
		}

		void Puthandcuff()
		{
			std::cout<<"snap"<<std::endl;
			handcuffs--;
		}

		void Shut()
		{
			if(pistol==NULL||pistol->Empty_bullet()<=0)
				std::cout<<"hut bang"<<std::endl;
			else
			{
				std::cout<<pistol->Empty_bullet();
				pistol->Shut();
			}
		}

		~Police()
		{
			if(pistol!=NULL)
				delete pistol;
		}
};

int main(void)
{
//	Police pman1(5,3);
//	pman1.Shut();
//	pman1.Puthandcuff();
//
	Police pman2(10,3);
	pman2.Shut();
	pman2.Puthandcuff();

	std::cout<<"-----"<<std::endl;

	Police pman3(2,1);
	Police pman4=pman3;

	pman3.Shut();
	pman3.Shut();
	pman3.Shut();

	std::cout<<"-----"<<std::endl;

	pman4.Puthandcuff();
	pman4.Shut();
	pman4.Shut();
	
	std::cout<<"-----"<<std::endl;

	pman2=pman3;
	pman2.Shut();
	pman2.Puthandcuff();

	return 0;
}
