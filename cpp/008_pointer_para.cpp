#include<iostream>

class FruitSeller{
	private:
		const int apple_price; //initializer can use constant 
		int apple_num;
		int seller_money;

	public:
		//void Init(int price,int num,int money);
		FruitSeller(int price,int num,int money):apple_price(price),apple_num(num),seller_money(money) {}
/*		{
			apple_price=price;
			apple_num=num;
			seller_money=money;
		}*/
		int SaleApples(int money);
		void Show() const;
		~FruitSeller()
		{

		}
};

class FruitBuyer{
	private:
		int apple_num;
		int buyer_money;

	public:
		//void Init(int money);
		FruitBuyer(int money):buyer_money(money),apple_num(0) {}
/*		{
			buyer_money=money;
			apple_num=0;
		}*/
		void BuyApples(FruitSeller &seller,int money);
		void BuyApples(FruitSeller *(&seller),int money);
		void Show() const;
		~FruitBuyer()
		{

		}
};

/*void FruitSeller::Init(int price,int num,int money)
{
	apple_price=price;
	apple_num=num;
	seller_money=money;
}*/

int FruitSeller::SaleApples(int money)
{
	if(money<0)
	{
		std::cout<<"iligal input"<<std::endl;
		return 0;
	}

	int num=money/apple_price;
	apple_num-=num;
	seller_money+=money;
	return num;
}

void FruitSeller::Show() const
{
	std::cout<<"seller apple:"<<apple_num<<std::endl;
	std::cout<<"seller money:"<<seller_money<<std::endl;
}

/*void FruitBuyer::Init(int money)
{
	buyer_money=money;
	apple_num=0;
}*/

void FruitBuyer::BuyApples(FruitSeller &seller,int money)
{
	if(money<0)
	{
		std::cout<<"iligal input"<<std::endl;
		return;
	}

	apple_num+=seller.SaleApples(money);
	buyer_money-=money;
}

void FruitBuyer::BuyApples(FruitSeller *(&seller),int money)
{
	if(money<0)
	{
		std::cout<<"iligal input"<<std::endl;
		return;
	}

	apple_num+=seller->SaleApples(money);
	buyer_money-=money;
}
void FruitBuyer::Show() const
{
	std::cout<<"buyer apple:"<<apple_num<<std::endl;
	std::cout<<"buyer money:"<<buyer_money<<std::endl;
}

int main(void)
{
	//FruitSeller seller1;
	//FruitSeller *seller2 = new FruitSeller;
	//FruitBuyer buyer;

	//seller1.Init(1000,20,0);
	//seller2->Init(1500,50,0);
	//buyer.Init(5000);
	
	FruitSeller seller1(1000,20,0);
	FruitSeller *seller2 = new FruitSeller(1500,50,0);
	FruitBuyer buyer(5000);

	buyer.Show();
	buyer.BuyApples(seller1,2000);
	buyer.Show();
	buyer.BuyApples(*seller2,3000);
	buyer.Show();
	seller1.Show();
	seller2->Show();

	delete seller2;

	return 0;
}
