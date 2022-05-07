#include<iostream>

class SortRule
{
	public:
		virtual bool operator()(int num1,int num2) const =0;
};

class AscendingSort:public SortRule
{
	public:
		bool operator()(int num1,int num2) const
		{
			if(num1>num2)
				return true;
			else
				return false;
		}
};

class DeseandingSort:public SortRule
{
	public:
		bool operator()(int num1,int num2) const
		{
			if(num1<num2)
				return true;
			else
				return false;
		}
};

class DataStorage
{
	private:
		int *arr;
		int idx;
		int max;
	public:
		DataStorage(int arrlen):idx(0),max(arrlen){arr=new int[max];}
		void AddData(int num)
		{
			if(max<=idx)
			{
				std::cout<<"no more save file"<<std::endl;
				return;
			}
			arr[idx++]=num;
		}
		void Show() const
		{
			for(int i=0;i<idx;i++)
				std::cout<<arr[i]<<' ';
			std::cout<<std::endl;
		}
		void SortData(const SortRule& functor)
		{
			for(int i=0;i<(idx-1);i++)
			{
				for(int j=0;j<(idx-1);j++)
				{
					if(functor(arr[j],arr[j+1]))
					{
						int temp=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temp;
					}
				}
			}
		}
};

int main(void)
{
	DataStorage stor(5);
	stor.AddData(5);
	stor.AddData(2);
	stor.AddData(4);
	stor.AddData(1);
	stor.AddData(3);

	stor.SortData(AscendingSort());	//temporary object create of AscendingSort
	stor.Show();

	stor.SortData(DeseandingSort());
	stor.Show();
}
