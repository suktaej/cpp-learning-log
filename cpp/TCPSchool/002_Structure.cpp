#include<iostream>

using namespace std;

struct Name
{
    string first;
    string last;
};

struct book
{
    string title;
    //string author;
    struct Name author;
    int price;
    int sale;
};

typedef struct
{
    string title;
    //string author;
    struct Name author;
    int price;
    int sale;
} Book;

int Calc(int, int);
int fpCalc(int,int (*fp)(int,int));
int PtrCalc(const Book*);

int main(void)
{
    struct book webBook = {"HTML&CSS",{"Kim","NARA"},28000,10000};
    Book javaBook = {"Java",{"Lee","DARE"},10000,5000};
    Book* ptrBook;

    ptrBook = &javaBook;
    int salePrice;

    salePrice = Calc(webBook.price,webBook.sale);
    cout<<webBook.author.first<<webBook.author.last<<"\\"<<webBook.title<<"\\"<<webBook.price<<"\\"<<salePrice<<endl;
    
    salePrice = PtrCalc(&javaBook);
    cout<<javaBook.author.first<<javaBook.author.last<<"\\"<<javaBook.title<<"\\"<<javaBook.price<<"\\"<<salePrice<<endl;

    salePrice = fpCalc(webBook.price,Calc);
    cout<<salePrice<<endl;
    return 0;
}

int Calc(int a, int b)
{
    return (a-b);
}

int fpCalc(int a,int (*fp)(int,int))
{
    return fp(a,a);
}

int PtrCalc(const Book* wbook)
{
    //wbook->price=30000;
    return(wbook->price - wbook->sale);
}