#include<iostream>
#include<cstring>

class Book
{
	private:
		char *title;
		char *isbn;
		int price;
	public:
		Book(char* inp_title,char* inp_isbn,int inp_price):price(inp_price)
		{
			title=new char[strlen(inp_title)+1];
			isbn=new char[strlen(inp_isbn)+1];
			strcpy(title,inp_title);
			strcpy(isbn,inp_isbn);
		}
		~Book()
		{
			delete[] title;
			delete[] isbn;
		}
		void Show()
		{
			std::cout<<"title:"<<title<<std::endl;
			std::cout<<"ISBN:"<<isbn<<std::endl;
			std::cout<<"price:"<<price<<std::endl;
		}
};

class EBook:public Book
{
	private:
		char *DRMKey;
	public:
		EBook(char* inp_title,char* inp_isbn,int inp_price,char* drm):Book(inp_title,inp_isbn,inp_price)
		{
			DRMKey=new char[strlen(drm)+1];
			strcpy(DRMKey,drm);
		}
		~EBook()
		{
			delete[] DRMKey;
		}

		void Show()
		{
			Book::Show();
			std::cout<<"DRM key:"<<DRMKey<<std::endl;
		}
};

int main(void)
{
	Book b1("good","11111",10000);
	b1.Show();

	EBook eb1("goodE","22222",20000,"fkqnfje");
	eb1.Show();

	return 0;
}
